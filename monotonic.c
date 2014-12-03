#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


#if defined(HAVE_FUNC_GETTIMEOFDAY) && defined(HAVE_SYS_TIME_H)
#include <sys/time.h>
#endif

#if defined(HAVE_FUNC_TIME) || defined(HAVE_FUNC_CLOCK_GETTIME)
#include <time.h>
#endif

#if defined(HAVE_FUNC_GSTAFT)
#include <windows.h>
#endif

#if defined(HAVE_MACH_MACH_H)
#include <mach/mach.h>
#include <mach/clock.h>
# if defined(HAVE_FUNC_MACH_ABSOLUTE_TIME)
#  include <mach/mach_time.h>
# endif
#endif

#define SECS 1000000000llu
#define USECS 1000llu
#define MSECS 1000000llu
#define WINDOWS_EPOCH 116444736000000000llu /* in hundreds of nanosecond */

#if defined(HAVE_FUNC_CLOCK_GETTIME)
inline int clock_gettime_int64(clock_t clk, uint64_t* res) {
    struct timespec ts;
    int ret = clock_gettime(clk, &ts);
    if (ret == 0)
      *res = (int64_t)ts.tv_sec * SECS + (int64_t)ts.tv_nsec;
    return ret;
}
#endif

void main() {
  uint64_t value;

#if defined(HAVE_FUNC_CLOCK_GETTIME)

# if defined(CLOCK_MONOTONIC) // Linux, BSD (Free,Net,Open,DragonFly), AIX
  clock_gettime_int64(CLOCK_MONOTONIC, &value);
  printf("clock_gettime(MT)          %" PRId64 "\n", value);
# endif

# if defined(CLOCK_MONOTONIC_RAW) // Linux
  clock_gettime_int64(CLOCK_MONOTONIC_RAW, &value);
  printf("clock_gettime(MT_RAW)      %" PRId64 "\n", value);
# endif

# if defined(CLOCK_MONOTONIC_COARSE) // Linux
  clock_gettime_int64(CLOCK_MONOTONIC_COARSE, &value);
  printf("clock_gettime(MT_COARSE)   %" PRId64 "\n", value);
# endif

# if defined(CLOCK_BOOTTIME) // Linux
  clock_gettime_int64(CLOCK_BOOTTIME, &value);
  printf("clock_gettime(BOOTTIME)    %" PRId64 "\n", value);
# endif

# if defined(CLOCK_MONOTONIC_FAST) // FreeBSD, DragonFly BSD
  clock_gettime_int64(CLOCK_MONOTONIC_FAST, &value);
  printf("clock_gettime(MT_FAST)     %" PRId64 "\n", value);
# endif

# if defined(CLOCK_MONOTONIC_PRECISE) // FreeBSD, DragonFly BSD
  clock_gettime_int64(CLOCK_MONOTONIC_PRECISE, &value);
  printf("clock_gettime(MT_PRECISE)  %" PRId64 "\n", value);
# endif

# if defined(CLOCK_UPTIME) // FreeBSD, DragonFly BSD
  clock_gettime_int64(CLOCK_UPTIME, &value);
  printf("clock_gettime(UPTIME)      %" PRId64 "\n", value);
# endif

# if defined(CLOCK_UPTIME_FAST) // FreeBSD, DragonFly BSD
  clock_gettime_int64(CLOCK_UPTIME_FAST, &value);
  printf("clock_gettime(UT_FAST)     %" PRId64 "\n", value);
# endif

# if defined(CLOCK_UPTIME_PRECISE) // FreeBSD, DragonFly BSD
  clock_gettime_int64(CLOCK_UPTIME_PRECISE, &value);
  printf("clock_gettime(UT_PRECISE)  %" PRId64 "\n", value);
# endif

# if defined(CLOCK_HIGHRES) // Solaris
  clock_gettime_int64(CLOCK_HIGHRES, &value);
  printf("clock_gettime(HIGHRES)     %" PRId64 "\n", value);
# endif

#endif

#if defined(HAVE_FUNC_GETTICKCOUNT) // Windows
  value = GetTickCount()*MSECS;
  printf("GetTickCount               %" PRId64 "\n", value);
#endif

#if defined(HAVE_FUNC_GETTICKCOUNT64) // Windows Vista, Server 2008
  value = GetTickCount64()*MSECS;
  printf("GetTickCount64             %" PRId64 "\n", value);
#endif

#if defined(HAVE_FUNC_QUERY_UNBIASED_INTERRUPT_TIME) // Windows 7, Server 2008 R2
  QueryUnbiasedInterruptTime(&value);
  // assert !=0;
  value *= 100;
  printf("QueryUnbiasedInterruptTime %" PRId64 "\n", value);
#endif

#if defined(HAVE_FUNC_CLOCK_GET_TIME)
  {
    clock_serv_t host_clock;
    kern_return_t kr = host_get_clock_service(mach_host_self(),
      SYSTEM_CLOCK, &host_clock);
    //assert(kr == KERNEL_SUCCESS);

    mach_timespec_t ts;
    clock_get_time(host_clock, &ts);
    value = ts.tv_sec* SECS + ts.tv_nsec;
    printf("clock_get_time(SYSTEM)     %" PRId64 "\n",value);
  }
#endif
}
