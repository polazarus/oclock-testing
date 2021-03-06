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
#endif


#define SECS 1000000000LL
#define USECS 1000LL
#define WINDOWS_EPOCH 116444736000000000LLU /* in hundreds of nanosecond */

void main() {
  uint64_t value;

#if defined(HAVE_FUNC_GSTAFT)
  {
    /*
     * We should be able to pass directly ((int64_t*)&value) to
     * GetSystemTimeAsFileTime on any standard Windows.
     * But what about Windows RT for ARM?
     */
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    value = (((uint64_t)ft.dwHighDateTime << 32) + ft.dwLowDateTime - WINDOWS_EPOCH)*100;
    printf("GetSystemTimePreciseAsFT   %" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_GSTPAFT)
  {
    /*
     * We should be able to pass directly ((int64_t*)&value) to
     * GetSystemTimeAsFileTime on any standard Windows.
     * But what about Windows RT for ARM?
     */
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    value = (((uint64_t)ft.dwHighDateTime << 32) + ft.dwLowDateTime - WINDOWS_EPOCH)*100;
    printf("GetSystemTimeAsFT          %" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_CLOCK_GETTIME)
  {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    value = ts.tv_sec* SECS + ts.tv_nsec;
    printf("clock_gettime(RT)          %" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_GETTIMEOFDAY)
  {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    value = tv.tv_sec* SECS + tv.tv_usec* USECS;
    printf("gettimeofday               %" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_TIME)
  {
    value = time(NULL)*SECS;
    printf("time                       %" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_CLOCK_GET_TIME)
  {
    clock_serv_t host_clock;
    kern_return_t kr = host_get_clock_service(mach_host_self(),
      CALENDAR_CLOCK, &host_clock);
    //assert(kr == KERNEL_SUCCESS);

    mach_timespec_t ts;
    clock_get_time(host_clock, &ts);
    value = ts.tv_sec* SECS + ts.tv_nsec;
    printf("clock_get_time(CALENDAR)     %" PRId64 "\n",value);
  }
#endif

}
