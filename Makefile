include Makefile.config

CCFLAGS+=-std=c11

all: wallclock

# let's use this implicit rules


clean:
	$(RM) wallclock wallclock.exe
