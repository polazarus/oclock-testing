include Makefile.config

CCFLAGS+=-std=c11

programs:=wallclock monotonic
programs:=$(programs:=$(EXEEXT))

all: $(programs)

%$(EXEEXT): %.c
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	$(RM) $(programs)
