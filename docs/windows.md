Windows
=======

## `GetSystemTimeAsFileTime`
*Windows 2000 Pro., Windows 2000 Server*

Time period since the "Windows Epoch", in hundreds of nanoseconds (10⁻⁷ s).
Subject to any time adjustement on the machine.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ms724397%28v=vs.85%29.aspx)

## `GetSystemTimePreciseAsFileTime`
*Windows 8, Windows Server 2012*

Idem but more precise.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/hh706895%28v=vs.85%29.aspx)

## `GetTickCount`
*Windows 2000 Pro., Windows 2000 Server*

Time period in milliseconds since the system was started.
Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ms724408%28v=vs.85%29.aspx)

## `GetTickCount64`
*at least Vista, Windows Server 2008*

Time period in milliseconds since the system was started.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ms724411%28v=vs.85%29.aspx)

## `QueryUnbiasedInterruptTime`
*Windows 7 or Windows Server 2008 R2*

Time period in hundreds of nanoseconds since the system was started
excluding time spent in sleep or hibernation.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ee662307%28v=vs.85%29.aspx)

## `QueryPerformanceCounter`
*Windows 2000*

Get value of counter started at an unspecified time in the past, that is
incremented at a certain frequency. The frequency can be fetch as an
integer in Hz through `QueryPerformanceFrequency`.

Source: [MSDN](http://msdn.microsoft.com/en-us/library/windows/desktop/ms644904%28v=vs.85%29.aspx)

## `GetProcessTimes`
*Windows XP, Windows Server 2003*

Process times (real and user)

Source: [MSDN](http://msdn.microsoft.com/en-us/library/ms683223%28VS.85%29.aspx)

