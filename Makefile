include Makefile.common

ADATA = $(foreach dir,src/data,$(notdir $(wildcard $(dir)/*.s)))
CDATA = $(foreach dir,src/data,$(notdir $(wildcard $(dir)/*.c)))
MDATA = $(foreach dir,src/data/$(MUSIC_DRIVER),$(notdir $(wildcard $(dir)/*.c)))
EXAMPLES = $(foreach dir,examples,$(wildcard $(dir)/*))

OBJS = $(ENGINE_OBJS) \
	$(ADATA:%.s=$(OBJDIR)/%.o) \
	$(CDATA:%.c=$(OBJDIR)/%.o) \
	$(MDATA:%.c=$(OBJDIR)/%.o)
	
REL_OBJS = $(OBJS:$(OBJDIR)/%.o=$(REL_OBJDIR)/%.rel)

$(OBJDIR)/%.o:	src/data/$(MUSIC_DRIVER)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<	

$(OBJDIR)/%.o:	src/data/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:	src/data/%.s
	$(CC) $(CFLAGS) -c -o $@ $<	

$(REL_OBJS):			$(OBJS)
$(ROM_BUILD_DIR)/%.gb:	$(REL_OBJS)

.PHONY: 	examples
examples:
	@for example in $(EXAMPLES) ; do \
		$(MAKE) -C $$example ; \
	done
