include Makefile.config

CCFLAGS+=-std=c11

all: wallclock$(EXEEXT)

%$(EXEEXT): %.c
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	$(RM) wallclock wallclock.exe
