MacOS X and iOS
===============

`clock_get_time`
----------------
*declared in `mach/clock.h`*

Monotonic time in nanoseconds.

    ~~~~ C
    /* once */
    clock_serv_t host_clock;
    kern_return_t kr = host_get_clock_service(mach_host_self(),
      SYSTEM_CLOCK, &host_clock);
    assert(kr == KERNEL_SUCCESS);

    mach_timespec_t now;
    clock_get_time(host_clock, &now);
    ~~~~

Montonic clocks:

  * `SYSTEM_CLOCK` since boottime.
  * `CALENDAR_CLOCK` since the Epoch
  * (deprecated) `REALTIME_CLOCK`, now a synonym for `SYSTEM_CLOCK`

Source: <https://opensource.apple.com/source/xnu/xnu-2782.1.97/osfmk/mach/clock_types.h>


`mach_absolute_time`
--------------------
*declared in `mach/time.h`*

Monotonic in some arbitrary unit. `mach_timebase_info` returns the duration of a unit in nanoseconds as a rational.

Sources:
  * <https://opensource.apple.com/source/xnu/xnu-2782.1.97/osfmk/mach/mach_time.h>
  * <http://stackoverflow.com/questions/20817311/ios-real-monotonic-clock-other-than-mach-absolute-time>
