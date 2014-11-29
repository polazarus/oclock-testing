#include "config.h"

#include <stdlib.h>

#if defined(HAVE_FUNC_GETTIMEOFDAY) && defined(HAVE_SYS_TIME_H)
#include <sys/time.h>
#endif

#if defined(HAVE_FUNC_TIME) || defined(HAVE_FUNC_CLOCK_GETTIME)
#include <time.h>
#endif

#include <stdio.h>
#include <inttypes.h>


#define SECS 1000000000LL
#define USECS 1000LL

void main() {
  int64_t value;

#if defined(HAVE_FUNC_CLOCK_GETTIME)
  {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    value = ts.tv_sec* SECS + ts.tv_nsec;
    printf("clock_gettime(RT)   %20" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_GETTIMEOFDAY)
  {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    value = tv.tv_sec* SECS + tv.tv_usec* USECS;
    printf("gettimeofday        %20" PRId64 "\n",value);
  }
#endif

#if defined(HAVE_FUNC_TIME)
  {
    value = time(NULL)*SECS;
    printf("time                %20" PRId64 "\n",value);
  }
#endif
}
