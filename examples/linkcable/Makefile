include ../../Makefile.common
include ./Makefile.build
include ../Makefile.project

.PHONY: data
data:
	$(GBS_CLI) export -d project/linkcable.gbsproj data

run: all
	($(EMU) $(TARGET) --listen 127.0.0.1:8765 &); \
	($(EMU) $(TARGET) --connect 127.0.0.1:8765 &); \
