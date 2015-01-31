`clock_gettime` family of functions
===================================

~~~~ C
// time.h
int clock_getres(clockid_t clk_id, struct timespec *res);
int clock_gettime(clockid_t clk_id, struct timespec *tp);
int clock_settime(clockid_t clk_id, const struct timespec *tp);
int clock_getcpuclockid(pid_t pid, clockid_t *clock_id);

// pthread.h time.h
int pthread_getcpuclockid(pthread_t thread, clockid_t *clock_id);
~~~~


## POSIX

  * `CLOCK_REALTIME`: time period since the Epoch
  * `CLOCK_MONOTONIC`
  * `CLOCK_PROCESS_CPUTIME_ID` if `_POSIX_CPUTIME` is defined
  * `CLOCK_THREAD_CPUTIME_ID` if `_POSIX_THREAD_CPUTIME` is defined

Also, functions:
  * `clock_getcpuclockid` if `_POSIX_CPUTIME` is defined
  * `pthread_getcpuclockid` if `_POSIX_THREAD_CPUTIME` is defined

Source: [Open Group Base Specifications Issue 7](http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html)

## Linux

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
    Atomic Time), UTC without leap seconds

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Sources:
  * [source code](https://github.com/torvalds/linux/blob/master/include/uapi/linux/time.h)
  * [man page](http://man7.org/linux/man-pages/man2/clock_gettime.2.html)

## BSD

### OpenBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`: contains suspend (POSIX!)
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`
  * `CLOCK_UPTIME`: time the system has been running

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Sources:
  * [source code](http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/sys/sys/_time.h)
  * [man page](http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man2/clock_getres.2)

### FreeBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_UPTIME`: time the system have been running (`CLOCK_MONOTONIC`
    minus time in suspend)
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

Sources:
  * [source code](https://github.com/freebsd/freebsd/blob/master/include/time.h)
  * [man page](https://www.freebsd.org/cgi/man.cgi?query=clock_gettime)

### NetBSD

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`
  * `CLOCK_VIRTUAL`
  * `CLOCK_PROF`

Sources:
  * [source code](http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/sys/time.h)
  * [man page](http://netbsd.gw.com/cgi-bin/man-cgi?clock_getres+2+NetBSD-current)

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

Sources:
  * [source code](https://github.com/DragonFlyBSD/DragonFlyBSD/blob/master/include/time.h)
  * [man page](http://leaf.dragonflybsd.org/cgi/web-man?command=clock_gettime&section=2)

## Unix

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

## Others

### QNX

  * `CLOCK_SOFTTIME`: like `CLOCK_REALTIME`, active only when the
    processor isn't in a power-saving mode

Also, functions:
  * `clock_getcpuclockid`
  * `pthread_getcpuclockid`

Source: [man page](http://www.qnx.com/developers/docs/660/topic/com.qnx.doc.neutrino.lib_ref/topic/c/clock_gettime.html)


### GNU Hurd

  * `CLOCK_REALTIME`
  * `CLOCK_MONOTONIC`: tick in suspend?
  * `CLOCK_PROCESS_CPUTIME_ID`
  * `CLOCK_THREAD_CPUTIME_ID`
  * `CLOCK_MONOTONIC_RAW`: "Monotonic system-wide clock, not adjusted for frequency scaling", what does it mean?
  * `CLOCK_REALTIME_COARSE`
  * `CLOCK_MONOTONIC_COARSE`

Source: [source code](http://git.savannah.gnu.org/cgit/hurd/glibc.git/tree/bits/time.h)
