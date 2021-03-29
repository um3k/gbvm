include ../../Makefile.common

ADATA = $(foreach dir,data/src/data,$(notdir $(wildcard $(dir)/*.s)))
CDATA = $(foreach dir,data/src/data,$(notdir $(wildcard $(dir)/*.c)))
MDATA = $(foreach dir,data/src/data/$(MUSIC_DRIVER),$(notdir $(wildcard $(dir)/*.c)))

OBJS = $(filter-out $(TOP)$(OBJDIR)/main.o, $(ENGINE_OBJS)) \
	$(ADATA:%.s=$(OBJDIR)/%.o) \
	$(CDATA:%.c=$(OBJDIR)/%.o) \
	$(MDATA:%.c=$(OBJDIR)/%.o) \
	$(TOP)$(OBJDIR)/test_main.o \
	$(OBJDIR)/test.o
	
REL_OBJS_LOCAL = $(OBJS:$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)
REL_OBJS       = $(REL_OBJS_LOCAL:$(TOP)$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)

CFLAGS += -Idata/include -Wa-Idata/include -I..
EMUFLAGS += $(EMU_FORCE_DMG)

$(OBJDIR)/%.o:	data/src/data/$(MUSIC_DRIVER)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJDIR)/%.o:	data/src/data/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	data/src/data/%.s
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJDIR)/%.o:	test.c
	$(CC) $(CFLAGS) -c -o $@ $<	

$(REL_OBJDIR)/.rel:		$(OBJS)
$(ROM_BUILD_DIR)/%.gb:	$(REL_OBJS)

test: directories $(ROM_BUILD_DIR)/rom.gb test.json
	@echo "Running tests..."
	@$(EMU) $(EMUFLAGS) -rom $(ROM_BUILD_DIR)/rom.gb
	@$(TEST_CHK) test.json $(ROM_BUILD_DIR)/rom.noi $(ROM_BUILD_DIR)/rom.sna capture.bmp
