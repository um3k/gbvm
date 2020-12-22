CC = ../../gbdk/bin/lcc
TEST_DIR = ./test
TEST_FW	= $(TEST_DIR)/framework
EMU	= ../../bgb/bgb
GBSPACK = gbspack
TEST_CHK = python $(TEST_FW)/unit_checker.py

CART_SIZE = 8

ROM_BUILD_DIR = build
OBJDIR = obj
REL_OBJDIR = obj/_rel

CFLAGS = -Iinclude -Wa-Iinclude

LFLAGS_NBANKS += -Wl-yo$(CART_SIZE) -Wl-ya4 -Wl-j

LFLAGS = -Wl-yt0x1A $(LFLAGS_NBANKS)

TARGET = $(ROM_BUILD_DIR)/rom.gb

ASRC = $(foreach dir,src,$(notdir $(wildcard $(dir)/*.s))) 
CSRC = $(foreach dir,src,$(notdir $(wildcard $(dir)/*.c))) 

ACORE = $(foreach dir,src/core,$(notdir $(wildcard $(dir)/*.s))) 
CCORE = $(foreach dir,src/core,$(notdir $(wildcard $(dir)/*.c))) 
ADATA = $(foreach dir,src/data,$(notdir $(wildcard $(dir)/*.s)))
CDATA = $(foreach dir,src/data,$(notdir $(wildcard $(dir)/*.c)))

OBJS = $(CSRC:%.c=$(OBJDIR)/%.o) $(ASRC:%.s=$(OBJDIR)/%.o) $(ACORE:%.s=$(OBJDIR)/%.o) $(CCORE:%.c=$(OBJDIR)/%.o) $(ADATA:%.s=$(OBJDIR)/%.o) $(CDATA:%.c=$(OBJDIR)/%.o)
COREOBJS = $(ACORE:%.s=$(OBJDIR)/%.o) $(CCORE:%.c=$(OBJDIR)/%.o) $(ADATA:%.s=$(OBJDIR)/%.o) $(CDATA:%.c=$(OBJDIR)/%.o)
DATAOBJS = $(ADATA:%.s=$(OBJDIR)/%.o) $(CDATA:%.c=$(OBJDIR)/%.o)
REL_OBJS = $(OBJS:$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)

all:	$(TARGET) symbols
test: pretest runtest

.PHONY: clean release debug color profile test
.SECONDARY: $(OBJS) 

release:
	$(eval CFLAGS += -Wf'--max-allocs-per-node 50000')
	@echo "RELEASE mode ON"
	
debug:
	$(eval CFLAGS += -Wf--debug -Wl-m -Wl-w -Wl-y -Wf-DVM_DEBUG_OUTPUT)
	$(eval CFLAGS += -Wf--nolospre -Wf--nogcse)
	$(eval LFLAGS += -Wf--debug -Wl-m -Wl-w -Wl-y)
	@echo "DEBUG mode ON"

color:
	$(eval CFLAGS += -DCGB)
	$(eval LFLAGS += -Wm-yC)
	@echo "COLOR mode ON"

profile:
	$(eval CFLAGS += -Wf--profile)
	@echo "PROFILE mode ON"

$(OBJDIR)/%.o:	src/core/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	src/core/%.s
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	src/data/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	src/data/%.s
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJDIR)/%.o:	src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	src/%.s
	$(CC) $(CFLAGS) -c -o $@ $<

$(REL_OBJS):	$(OBJS)
	mkdir -p $(REL_OBJDIR)
	$(eval CART_SIZE=$(shell $(GBSPACK) -b 2 -e rel -c -o $(REL_OBJDIR) $(OBJS)))

$(ROM_BUILD_DIR)/%.gb:	$(REL_OBJS)
	mkdir -p $(ROM_BUILD_DIR)
	$(CC) $(LFLAGS) -o $@ $^

$(OBJDIR)/test_main.o: test/framework/test_main.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "CLEANUP..."
	rm -rf obj/*
	rm -rf $(ROM_BUILD_DIR)
	rm -f $(TEST_DIR)/*.noi
	rm -f $(TEST_DIR)/*.map
	rm -f $(TEST_DIR)/*.gb
	rm -f $(TEST_DIR)/*.sna
	rm -f $(TEST_DIR)/*.bmp	

rom: $(TARGET)

symbols:
	python ./utils/noi2sym.py $(patsubst %.gb,%.noi,$(TARGET)) >$(patsubst %.gb,%.sym,$(TARGET))

pretest: $(COREOBJS)
	$(CC) -c -o $(OBJDIR)/test_main.o $(TEST_FW)/main.c

runtest: $(TEST_DIR)/*.json
	@echo "Running tests..."
	@for file in $(patsubst %.json,%,$^) ; do \
		$(CC) $(CFLAGS) $(LFLAGS) -o $${file}.gb $(OBJDIR)/test_main.o $(COREOBJS) $${file}.c; \
		$(EMU) -set "DebugSrcBrk=1" -hf -stateonexit -screenonexit ./$${file}.bmp -rom $${file}.gb; \
		$(TEST_CHK) $${file}.json $${file}.noi $${file}.sna $${file}.bmp ; \
	done
