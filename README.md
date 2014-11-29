OClock Testing Ground
=====================
Various experiments on time implementation for OClock.

~~~~shell
./configure
make
~~~~


Cross-compiling notes
---------------------

  * On ArchLinux, `x86_64-w64-mingw32-gcc` builds with the `-pthread` flag
    by default.  I don't see the point really here, except that winpthread
    has a pretty good implementation of `clock_gettime`.  But who really
    want to get that additional dependency?

    ~~~~shell
    ./configure CFLAGS=-no-pthread # should it be in LDFLAGS?
    ~~~~
