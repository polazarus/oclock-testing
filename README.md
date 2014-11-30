OClock Testing Ground
=====================
Various experiments on time implementation for OClock.

~~~~shell
./configure
make
~~~~

Windows
-------

### `GetSystemTimeAsFileTime`
*Windows 2000*

Time period since the "Windows Epoch", in hundreds of nanoseconds (10⁻⁷ s).
Subject to any time adjustement on the machine.

### `GetSystemTimePreciseAsFileTime`
*at least Windows 8, Windows Server 2012*

Idem but more precise.

### `GetTickCount`, monotonic
*Windows 2000*

Time period in milliseconds since the system was started.
Monotonic

### `GetTickCount64`, monotonic
*at least Vista, Windows Server 2008*

Time period in milliseconds since the system was started.

### `QueryPerformanceCounter`, monotonic
*Windows 2000*

Get value of counter started at an unspecified time in the past, that is
incremented at a certain frequency. The frequency can be fetch as an
integer in Hz through `QueryPerformanceFrequency`.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ms644904%28v=vs.85%29.aspx)


### `GetProcessTimes`, process times (real and user)
*Windows XP, Windows Server 2003*

Source: [MSDN](http://msdn.microsoft.com/en-us/library/ms683223%28VS.85%29.aspx)


`clock_gettime` functions
-------------------------

### POSIX

  * `CLOCK_REALTIME`: time period since the Epoch
  * `CLOCK_MONOTONIC`
  * `CLOCK_PROCESS_CPUTIME_ID` if `_POSIX_CPUTIME` is defined
  * `CLOCK_THREAD_CPUTIME_ID` if `_POSIX_THREAD_CPUTIME` is defined

Also, functions:
  * `clock_getcpuclockid` if `_POSIX_CPUTIME` is defined
  * `pthread_getcpuclockid` if `_POSIX_THREAD_CPUTIME` is defined

Source: [Open Group Base Specifications Issue 7](http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html)

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
  * `CLOCK_REALTIME_ALARM`: since 3.0, like `CLOCK_REALTIME`, but also
    wakes suspended system
  * `CLOCK_BOOTTIME_ALARM`: since 3.0, like `CLOCK_BOOTTIME`, idem
  * `CLOCK_TAI`: since 3.10, "Temps Atomic International" (International
    Atomic Time)

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Sources:
  * [source code](https://github.com/torvalds/linux/blob/master/include/uapi/linux/time.h)
  * [man page](http://man7.org/linux/man-pages/man2/clock_gettime.2.html)

### OpenBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`: contains suspend (POSIX!)
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`
  * `CLOCK_UPTIME`: time the system has been running

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Source:
  * [source code](http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/sys/sys/_time.h)
  * [man page](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/clock_getres.2)

### NetBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`

Source: [source code](http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/sys/time.h)

### FreeBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_UPTIME`: time the system have been running (`CLOCK_MONOTONIC` minus
    time in suspend)
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`
  * `CLOCK_REALTIME_FAST`
  * `CLOCK_MONOTONIC_FAST`
  * `CLOCK_REALTIME_PRECISE`
  * `CLOCK_MONOTONIC_PRECISE`
  * `CLOCK_UPTIME_FAST`
  * `CLOCK_UPTIME_PRECISE`
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Source:
  * [source code](https://github.com/freebsd/freebsd/blob/master/include/time.h)
  * [man page](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/clock_getres.2)

### NetBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`

Source: [source code](http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/sys/time.h)

### DragonFly

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

Source: [source code](https://github.com/DragonFlyBSD/DragonFlyBSD/blob/master/include/time.h)

### AIX

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

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
    processor isn't in a power-saving mode

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Source: [man page](http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.neutrino.lib_ref/topic/c/clock_gettime.html)


`gethr*time` functions
----------------------

### `gethrtime`
*HP-UX, Solaris*

Monotonic time as a signed 64-bit integer in nanoseconds.

Source:
  * [HP-UX man page](http://h20565.www2.hp.com/hpsc/doc/public/display?docId=emr_na-c02263260)
  * [Solaris man page](https://docs.oracle.com/cd/E36784_01/html/E36874/gethrtime-3c.html)

### `gethrvtime`
*Solaris*

`v` for virtual time as a signed 64-bit integer in nanoseconds.

Source: [Solaris man page](https://docs.oracle.com/cd/E36784_01/html/E36874/gethrtime-3c.html)


MacOS X's `mach_absolute_time`
------------------------------

`mach_timebase_info`


Cross-compiling notes
---------------------

  * On ArchLinux, `x86_64-w64-mingw32-gcc` builds with the `-pthread` flag
    by default.  I don't see the point really here, except that winpthread
    has a pretty good implementation of `clock_gettime`.  But who really
    want to get that additional dependency?

    ~~~~shell
    ./configure CFLAGS=-no-pthread # should it be in LDFLAGS?
    ~~~~
