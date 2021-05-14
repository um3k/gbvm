include ../../Makefile.common
include ./Makefile.build

ADATA = $(foreach dir,data/src/data,$(notdir $(wildcard $(dir)/*.s)))
CDATA = $(foreach dir,data/src/data,$(notdir $(wildcard $(dir)/*.c)))
MDATA = $(foreach dir,data/src/data/music,$(notdir $(wildcard $(dir)/*.c)))

OBJS = $(ENGINE_OBJS) \
	$(ADATA:%.s=$(OBJDIR)/%.o) \
	$(CDATA:%.c=$(OBJDIR)/%.o) \
	$(MDATA:%.c=$(OBJDIR)/%.o)
	
REL_OBJS_LOCAL = $(OBJS:$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)
REL_OBJS       = $(REL_OBJS_LOCAL:$(TOP)$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)

CFLAGS += -Idata/include -Wa-Idata/include

$(OBJDIR)/%.o:	data/src/data/music/%.c
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJDIR)/%.o:	data/src/data/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	data/src/data/%.s
	$(CC) $(CFLAGS) -c -o $@ $<	

$(REL_OBJDIR)/.rel:		$(OBJS)
$(ROM_BUILD_DIR)/%.gb:	$(REL_OBJS)

.PHONY: data
data:
	$(GBS_CLI) export -d project/name_picker.gbsproj data
