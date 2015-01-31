OClock Testing Ground
=====================
Various experiments on time implementation for OClock.

~~~~shell
./configure
make
~~~~

Clock functions
---------------

  * [Windows](docs/windows.md)
  * Unix/Linux
      * [`clock_gettime` family of functions](docs/clock_gettime.md)
      * [`gethrtime` family of functions](docs/gethrtime.md)
  * [MacOS X](docs/macosx.md)

Similar docs:

  * [Python PEP 418](https://www.python.org/dev/peps/pep-0418)

    Says weird things about `GetSystemTimeAdjustment`.
    But overall very interesting.

  * [C/C++ tip: How to measure elapsed real time for benchmarking](http://nadeausoftware.com/articles/2012/04/c_c_tip_how_measure_elapsed_real_time_benchmarking)


Cross-compiling notes
---------------------

  * On ArchLinux, `x86_64-w64-mingw32-gcc` builds with the `-pthread` flag
    by default.  I don't see the point really here, except that winpthread
    has some good implementation of `clock_gettime`.  But who really  want
    to get that additional dependency?

    ~~~~shell
    ./configure CFLAGS=-no-pthread # should it be in LDFLAGS?
    ~~~~
