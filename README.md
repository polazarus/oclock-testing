OClock Testing Ground
=====================
Various experiments on time implementation for OClock.

~~~~shell
./configure
make
~~~~

Clocks of `clock_gettime`
-------------------------

### POSIX
  * `CLOCK_REALTIME`: found in Linux, BSD (FreeBSD, DragonFly, NetBSD,
    OpenBSD), AIX, QNX

  * `CLOCK_MONOTONIC`

Source: open group

### Linux
  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`: does not tick when system is suspend, contrarily to
    what POSIX prescribes
  * `CLOCK_PROCESS_CPUTIME_ID`: since 2.6.12
  * `CLOCK_THREAD_CPUTIME_ID`: since 2.6.12
  * `CLOCK_MONOTONIC_RAW`: since 2.6.28, better `MONOTONIC`
  * `CLOCK_REALTIME_COARSE`: since 2.6.32
  * `CLOCK_MONOTONIC_COARSE`: since 2.6.32
  * `CLOCK_BOOTTIME`: since 2.6.39, like `CLOCK_MONOTONIC` but ticks in
    suspend, i.e. it's the true `CLOCK_MONOTONIC` (!!)
  * `CLOCK_REALTIME_ALARM`: since 3.0, like `CLOCK_REALTIME`, but also wakes
    suspended system
  * `CLOCK_BOOTTIME_ALARM`: since 3.0, like `CLOCK_BOOTTIME`, idem
  * `CLOCK_TAI`: since 3.10, "Temps Atomic International" (International
    Atomic Time)

Sources:
  * [Source code](https://github.com/torvalds/linux/blob/master/include/uapi/linux/time.h)
  * man page

### OpenBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`: contains suspend (POSIX!)
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`
  * `CLOCK_UPTIME`: time the system has been running

Source:
  * [Source code](http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/sys/sys/_time.h)
  * [man page](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/clock_getres.2)

### NetBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`

http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/sys/time.h

### FreeBSD, DragonFly

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_UPTIME`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`
  * `CLOCK_REALTIME_FAST`
  * `CLOCK_MONOTONIC_FAST`
  * `CLOCK_REALTIME_PRECISE`
  * `CLOCK_MONOTONIC_PRECISE`
  * `CLOCK_UPTIME_FAST`
  * `CLOCK_UPTIME_PRECISE`

Source:
  * [DragonFly source code](https://github.com/DragonFlyBSD/DragonFlyBSD/blob/master/include/time.h)
  * [FreeBSD source code](https://github.com/freebsd/freebsd/blob/master/include/time.h)

### AIX

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`

Source: [man page](http://www-01.ibm.com/support/knowledgecenter/ssw_aix_61/com.ibm.aix.basetrf1/clock_getres.htm)

### Solaris
  * `CLOCK_REALTIME`
  * `CLOCK_HIGHRES`: high-resolution monotonic, same source as `gethrtime`

Source: [man page](https://docs.oracle.com/cd/E36784_01/html/E36874/clock-gettime-3c.html)

### HP-UX
  * `CLOCK_REALTIME`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROFILE`

Source: [man page](http://h20565.www2.hp.com/hpsc/doc/public/display?docId=emr_na-c02259401)

### QNX
  * `CLOCK_SOFTTIME`: like `CLOCK_REALTIME`, active only when the
    processor isn.'t in a power-saving mode

Source: [man page](http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.neutrino.lib_ref/topic/c/clock_gettime.html)

Cross-compiling notes
---------------------

  * On ArchLinux, `x86_64-w64-mingw32-gcc` builds with the `-pthread` flag
    by default.  I don't see the point really here, except that winpthread
    has a pretty good implementation of `clock_gettime`.  But who really
    want to get that additional dependency?

    ~~~~shell
    ./configure CFLAGS=-no-pthread # should it be in LDFLAGS?
    ~~~~
