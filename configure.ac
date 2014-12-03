#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([oclock],
        [0.9.0],
        [https://github.com/polazarus/oclock/issues],
        [oclock],
        [https://github.com/polazarus/oclock/])

AC_CONFIG_SRCDIR([Makefile.config.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

################################################################################
# Checks for functions.                                                        #
################################################################################
# Windows
AC_CHECK_HEADERS([windows.h],[
  AC_CHECK_FUNC([QueryPerformanceCounter],[
    AC_DEFINE([HAVE_FUNC_QUERY_PERFORMANCE_COUNTER],[1],
              [Define if function QueryPerformanceCounter exists.])
  ])

  AC_CHECK_FUNC([QueryPerformanceFrequency],[
    AC_DEFINE([HAVE_FUNC_QUERY_PERFORMANCE_FREQUENCY],[1],
              [Define if function QueryPerformanceFrequency exists.])
  ])

  AC_CHECK_FUNC([QueryUnbiasedInterruptTime],[
    AC_DEFINE([HAVE_FUNC_QUERY_UNBIASED_INTERRUPT_TIME],[1],
              [Define if function QueryUnbiaisedInterruptTime exists.])
  ])

  AC_CHECK_FUNC([GetTickCount],[
    AC_DEFINE([HAVE_FUNC_GETTICKCOUNT],[1],
              [Define if function GetTickCount exists.])
  ])
  AC_CHECK_FUNC([GetTickCount64],[
    AC_DEFINE([HAVE_FUNC_GETTICKCOUNT64],[1],
              [Define if function GetTickCount64 exists.])
  ])

  AC_CHECK_FUNC([GetSystemTimeAsFileTime],[
    AC_DEFINE([HAVE_FUNC_GSTAFT],[1],
              [Define if GetSystemTimeAsFileTime exists.])
  ],[])

  AC_CHECK_FUNC([GetSystemTimePreciseAsFileTime],[
    AC_DEFINE([HAVE_FUNC_GSTPAFT],[1],
              [Define if GetSystemTimePreciseAsFileTime exists.])
  ],[])
])

################################################################################
# Mac
AC_CHECK_HEADERS([mach/mach.h],[

  AC_CHECK_FUNC([host_get_clock_service],[],[
    AC_DEFINE([HAVE_FUNC_HOST_GET_CLOCK_SERVICE],[1],
              [Define if host_get_clock_service exists.])
  ])

  AC_CHECK_HEADERS([mach/clock.h],[

    AC_CHECK_FUNC([clock_get_time],[],[
      AC_DEFINE([HAVE_FUNC_CLOCK_GET_TIME],[1],
                [Define if clock_get_time exists.])
    ])

  ])

  AC_CHECK_HEADERS([mach/mach_time.h],[

    AC_CHECK_FUNC([mach_timebase_info],[
      AC_DEFINE([HAVE_FUNC_MACH_TIMEBASE_INFO],[1],
                [Define if mach_timebase_info exists.])
    ])

    AC_CHECK_FUNC([mach_absolute_time],[
      AC_DEFINE([HAVE_FUNC_MACH_ABSOLUTE_TIME],[1],
                [Define if mach_absolute_time exists.])
    ])

  ])
])

################################################################################
# Solaris, HP-UX
AC_CHECK_FUNC([gethrtime],[
  AC_DEFINE([HAVE_FUNC_GETHRTIME],[1],[Define if gethrtime])
])

# Solaris
AC_CHECK_FUNC([gethrvtime],[
  AC_DEFINE([HAVE_FUNC_GETHRVTIME],[1],[Define if gethrvtime])
])

################################################################################
# Posix
AC_CHECK_HEADERS([time.h],[

  AC_CHECK_FUNC([clock_gettime],[
    AC_DEFINE([HAVE_FUNC_CLOCK_GETTIME],[1],
              [Define if function clock_gettime exists.])
  ],[
     # Checks with rt for older Linux
    AC_CHECK_LIB([rt],[clock_gettime],[
      LIBS="-lrt $LIBS"
      AC_DEFINE([HAVE_FUNC_CLOCK_GETTIME],[1],
                [Define if function clock_gettime exists.])
    ])
  ])

  AC_CHECK_FUNC([clock_getres],[
    AC_DEFINE([HAVE_FUNC_CLOCK_GETRES],[1],
              [Define if function clock_getres exists.])
  ])

  AC_CHECK_FUNC([time],[
    AC_DEFINE([HAVE_FUNC_TIME],[1],[Define if function time exists.])
  ],[])

])

AC_CHECK_HEADERS([sys/time.h],[
  AC_CHECK_FUNC([gettimeofday],[
    AC_DEFINE([HAVE_FUNC_GETTIMEOFDAY],[1],
              [Define if function gettimeofday exists.])
  ],[])
])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_DECL([CLOCK_REALTIME],[],[],[[#include <time.h>]])
AC_CHECK_DECL([CLOCK_MONOTONIC],[],[],[[#include <time.h>]])

# Checks for library functions.
AC_SUBST([HAVE_FUNC_QUERY_PERFORMANCE_COUNTER])
AC_SUBST([HAVE_FUNC_QUERY_PERFORMANCE_FREQUENCY])
AC_SUBST([HAVE_FUNC_GSTAFT])
AC_SUBST([HAVE_FUNC_GSTPAFT])
AC_SUBST([HAVE_FUNC_QUERY_UNBIASED_INTERRUPT_TIME])
AC_SUBST([HAVE_FUNC_HOST_GET_CLOCK_SERVICE])
AC_SUBST([HAVE_FUNC_CLOCK_GET_TIME])
AC_SUBST([HAVE_FUNC_MACH_ABSOLUTE_TIME])
AC_SUBST([HAVE_FUNC_MACH_TIMEBASE_INFO])
AC_SUBST([HAVE_FUNC_GETHRTIME])
AC_SUBST([HAVE_FUNC_GETHRVTIME])
AC_SUBST([HAVE_FUNC_CLOCK_GETTIME])
AC_SUBST([HAVE_FUNC_CLOCK_GETRES])
AC_SUBST([HAVE_FUNC_GETTIMEOFDAY])
AC_SUBST([HAVE_FUNC_TIME])


AC_CONFIG_FILES([Makefile.config])
AC_OUTPUT
