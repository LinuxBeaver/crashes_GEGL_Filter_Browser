This is NOT a GEGL plugin for my users but an example of how GIMP 3.1.2's unreleased still pending GEGL Filter Browser can crash GIMP.

A GSOC student is doing great work on a tool called "GEGL Filter Browser" but it has a problem with this third party plugin example. Let's dive into it.

![image](https://github.com/user-attachments/assets/a237db4d-7986-4554-b555-be871e9aeebc)

On line 43 we see my note. Put simply the crash happens because `part2` was accidentially defined twice when it should be part one. 
I know this is invalid GEGL code but it shouldn't crash the novel Filter Browser. I have faith this will be fixed.


Thank you MartyMichal! I hope you get as much enjoyment out of GEGL as I do.


Crash log below


```
<!-- Copy-paste this whole debug data to report to developers -->


```
GNU Image Manipulation Program version 3.0.5
git-describe: unknown (unsupported)
Build: unknown rev 0 for linux
# C compiler #
Using built-in specs.
COLLECT_GCC=/usr/bin/cc
COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/14/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-redhat-linux
Configured with: ../configure --enable-bootstrap --enable-languages=c,c++,fortran,objc,obj-c++,ada,go,d,m2,lto --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-gcc-major-version-only --enable-libstdcxx-backtrace --with-libstdcxx-zoneinfo=/usr/share/zoneinfo --with-linker-hash-style=gnu --enable-plugin --enable-initfini-array --with-isl=/builddir/build/BUILD/gcc-14.2.1-20240912/obj-x86_64-redhat-linux/isl-install --enable-offload-targets=nvptx-none,amdgcn-amdhsa --enable-offload-defaulted --without-cuda-driver --enable-gnu-indirect-function --enable-cet --with-tune=generic --with-arch_32=i686 --build=x86_64-redhat-linux --with-build-config=bootstrap-lto --enable-link-serialization=1
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 14.2.1 20240912 (Red Hat 14.2.1-3) (GCC) 

# Libraries #
using babl version 0.1.115 (compiled against version 0.1.115)
using GEGL version 0.4.63 (compiled against version 0.4.62)
using GLib version 2.80.5 (compiled against version 2.80.5)
using GdkPixbuf version 2.42.10 (compiled against version 2.42.10)
using GTK+ version 3.24.43 (compiled against version 3.24.43)
using Pango version 1.54.0 (compiled against version 1.54.0)
using Fontconfig version 2.15.0 (compiled against version 2.15.0)
using Cairo version 1.18.0 (compiled against version 1.18.0)
using gexiv2 version 0.14.3 (compiled against version 0.14.3)
using exiv2 version 0.27.6

```
> fatal error: Segmentation fault

Stack trace:
```

# Stack traces obtained from PID 778556 - Thread 778556 #

[New LWP 778670]
[New LWP 778662]
[New LWP 778652]
[New LWP 778643]
[New LWP 778629]
[New LWP 778579]
[New LWP 778577]
[New LWP 778576]
[New LWP 778575]
[New LWP 778574]
[New LWP 778573]
[New LWP 778572]
[New LWP 778571]
[New LWP 778570]
[New LWP 778559]
[New LWP 778558]
[New LWP 778557]

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.fedoraproject.org/>
Enable debuginfod for this session? (y or [n]) [answered N; input not from terminal]
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".
0x00007fbc1e06b7ca in read () from /lib64/libc.so.6
  Id   Target Id                                         Frame 
* 1    Thread 0x7fbc1bdda240 (LWP 778556) "gimp-3.0"     0x00007fbc1e06b7ca in read () from /lib64/libc.so.6
  2    Thread 0x7fbb7dffb6c0 (LWP 778670) "swap writer"  0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  3    Thread 0x7fbb4ffff6c0 (LWP 778662) "dashboard"    0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  4    Thread 0x7fbb5effd6c0 (LWP 778652) "dconf worker" 0x00007fbc1e06b1fd in poll () from /lib64/libc.so.6
  5    Thread 0x7fbb84c6d6c0 (LWP 778643) "pool-gimp"    0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  6    Thread 0x7fbb7ffff6c0 (LWP 778629) "gimp-3.0"     0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  7    Thread 0x7fbbd17fa6c0 (LWP 778579) "gimp-3.0"     0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  8    Thread 0x7fbbd27fc6c0 (LWP 778577) "async"        0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  9    Thread 0x7fbbd2ffd6c0 (LWP 778576) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  10   Thread 0x7fbbd37fe6c0 (LWP 778575) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  11   Thread 0x7fbbd3fff6c0 (LWP 778574) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  12   Thread 0x7fbbfc9256c0 (LWP 778573) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  13   Thread 0x7fbbfd1266c0 (LWP 778572) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  14   Thread 0x7fbbfd9276c0 (LWP 778571) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  15   Thread 0x7fbc04ffe6c0 (LWP 778570) "worker"       0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6
  16   Thread 0x7fbc0d9fe6c0 (LWP 778559) "gdbus"        0x00007fbc1e06b1fd in poll () from /lib64/libc.so.6
  17   Thread 0x7fbc057ff6c0 (LWP 778558) "gmain"        0x00007fbc1e06b1fd in poll () from /lib64/libc.so.6
  18   Thread 0x7fbc0e1ff6c0 (LWP 778557) "pool-spawner" 0x00007fbc1e076d5d in syscall () from /lib64/libc.so.6

Thread 18 (Thread 0x7fbc0e1ff6c0 (LWP 778557) "pool-spawner"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f44c63b in g_async_queue_pop_intern_unlocked () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f4b3bb3 in g_thread_pool_spawn_thread () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#5  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#6  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 17 (Thread 0x7fbc057ff6c0 (LWP 778558) "gmain"):
#0  0x00007fbc1e06b1fd in poll () at /lib64/libc.so.6
#1  0x00007fbc1f4e3dbc in g_main_context_iterate_unlocked.isra () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f483503 in g_main_context_iteration () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f483561 in glib_worker_main () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#5  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#6  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 16 (Thread 0x7fbc0d9fe6c0 (LWP 778559) "gdbus"):
#0  0x00007fbc1e06b1fd in poll () at /lib64/libc.so.6
#1  0x00007fbc1f4e3dbc in g_main_context_iterate_unlocked.isra () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f4880f7 in g_main_loop_run () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f2477a2 in gdbus_shared_thread_func.lto_priv () at /lib64/libgio-2.0.so.0
#4  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#5  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#6  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 15 (Thread 0x7fbc04ffe6c0 (LWP 778570) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f4201c0 <gegl_parallel_distribute_threads>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 14 (Thread 0x7fbbfd9276c0 (LWP 778571) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f4201f8 <gegl_parallel_distribute_threads+56>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 13 (Thread 0x7fbbfd1266c0 (LWP 778572) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f420230 <gegl_parallel_distribute_threads+112>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 12 (Thread 0x7fbbfc9256c0 (LWP 778573) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f420268 <gegl_parallel_distribute_threads+168>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 11 (Thread 0x7fbbd3fff6c0 (LWP 778574) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f4202a0 <gegl_parallel_distribute_threads+224>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 10 (Thread 0x7fbbd37fe6c0 (LWP 778575) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f4202d8 <gegl_parallel_distribute_threads+280>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 9 (Thread 0x7fbbd2ffd6c0 (LWP 778576) "worker"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f3548c3 in gegl_parallel_distribute_thread_func (thread=0x7fbc1f420310 <gegl_parallel_distribute_threads+336>) at ../gegl/gegl-parallel.c:508
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 8 (Thread 0x7fbbd27fc6c0 (LWP 778577) "async"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x000000000051b8e8 in gimp_parallel_run_async_thread_func (thread=0xaf4430 <gimp_parallel_run_async_threads>) at ../app/core/gimp-parallel.cc:377
        task = <optimized out>
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 7 (Thread 0x7fbbd17fa6c0 (LWP 778579) "gimp-3.0"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f44c63b in g_async_queue_pop_intern_unlocked () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f44c69c in g_async_queue_pop () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1edb80d9 in fc_thread_func () at /lib64/libpangoft2-1.0.so.0
#5  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#6  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#7  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 6 (Thread 0x7fbb7ffff6c0 (LWP 778629) "gimp-3.0"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f44c63b in g_async_queue_pop_intern_unlocked () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f44c69c in g_async_queue_pop () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1edb80d9 in fc_thread_func () at /lib64/libpangoft2-1.0.so.0
#5  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#6  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#7  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 5 (Thread 0x7fbb84c6d6c0 (LWP 778643) "pool-gimp"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e1030 in g_cond_wait_until () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f44c603 in g_async_queue_pop_intern_unlocked () at /lib64/libglib-2.0.so.0
#3  0x00007fbc1f44c756 in g_async_queue_timeout_pop () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1f4b458f in g_thread_pool_thread_proxy.lto_priv () at /lib64/libglib-2.0.so.0
#5  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#6  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#7  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 4 (Thread 0x7fbb5effd6c0 (LWP 778652) "dconf worker"):
#0  0x00007fbc1e06b1fd in poll () at /lib64/libc.so.6
#1  0x00007fbc1f4e3dbc in g_main_context_iterate_unlocked.isra () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f483503 in g_main_context_iteration () at /lib64/libglib-2.0.so.0
#3  0x00007fbc04261705 in dconf_gdbus_worker_thread () at /usr/lib64/gio/modules/libdconfsettings.so
#4  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#5  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#6  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 3 (Thread 0x7fbb4ffff6c0 (LWP 778662) "dashboard"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e1030 in g_cond_wait_until () at /lib64/libglib-2.0.so.0
#2  0x000000000073cf4a in gimp_dashboard_sample (dashboard=0x2baf9390) at ../app/widgets/gimpdashboard.c:1794
        update_interval = 250000
        sample_interval = <optimized out>
        end_time = <optimized out>
        priv = 0x2baf8650
        last_sample_time = 256812144012
        last_update_time = 256812144012
        seen_low_swap_space = 0
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 2 (Thread 0x7fbb7dffb6c0 (LWP 778670) "swap writer"):
#0  0x00007fbc1e076d5d in syscall () at /lib64/libc.so.6
#1  0x00007fbc1f4e0e4d in g_cond_wait () at /lib64/libglib-2.0.so.0
#2  0x00007fbc1f392479 in gegl_tile_backend_swap_writer_thread (ignored=<optimized out>) at ../gegl/buffer/gegl-tile-backend-swap.c:698
        params = <optimized out>
#3  0x00007fbc1f4b29c3 in g_thread_proxy () at /lib64/libglib-2.0.so.0
#4  0x00007fbc1dff5088 in start_thread () at /lib64/libc.so.6
#5  0x00007fbc1e078f8c in clone3 () at /lib64/libc.so.6

Thread 1 (Thread 0x7fbc1bdda240 (LWP 778556) "gimp-3.0"):
#0  0x00007fbc1e06b7ca in read () at /lib64/libc.so.6
#1  0x00007fbc1fa7eb13 in gimp_stack_trace_print (prog_name=<optimized out>, stream=stream@entry=0x2c112fd0, trace=trace@entry=0x0) at ../libgimpbase/gimputils.c:1390
        status = 3068
        stack_printed = 0
        gtrace = 0x0
        gimp_pid = "778556\000\000\000\000\000\000\000\000\000"
        buffer = "Pf\246\037\274\177\000\000@\350\247\037\274\177\000\000\v\000\000\000\000\000\000\000\260\236\220-\375\177\000\000\001\000\000\000\000\000\000\000`art2\000\000\0000\361\341\f\274\177\000\000\001\000\000\000\000\000\000\000\261\212\215\000\000\000\000\000\276f\253\037\274\177\000\000\320/\021,", '\000' <repeats 20 times>, "\320/\021,\000\000\000\000\020\004\377\006", '\000' <repeats 12 times>, "\001\000\000\000\000\000\000\000\001\000\000\000\274\177\000\000\340\222\255\037\274\177\000\000\030\233\220-\375\177\000\0000\233\220-\375\177\000\000\200\037\000\000\377\377\002\000(DC\037\274\177\000\000\200\032\242\037\274\177\000\000P\233\220-\375\177\000\000"...
        read_n = <optimized out>
        sync_fd = {23, 25}
        out_fd = {26, 27}
        fork_pid = <optimized out>
        pid = 778556
        eintr_count = 0
        tid = <optimized out>
#2  0x0000000000668dc0 in gimp_eek (reason=reason@entry=0x8d8ab1 "fatal error", message=<optimized out>, use_handler=use_handler@entry=1) at ../app/errors.c:363
        fd = 0x2c112fd0
        has_backtrace = 1
        pid = "778556\000\000o(\000\000\000\000\000"
        gimpdebug = 0x952040 "/home/contrast/Applications/gimp_nde/libexec/gimp-debug-tool-3.0"
        args = {0x952040 "/home/contrast/Applications/gimp_nde/libexec/gimp-debug-tool-3.0", 0x6ff0410 "/home/contrast/Applications/gimp_nde//bin/gimp-3.0", 0x7ffd2d909f00 "778556", 0x8d8ab1 "fatal error", 0x2b70acd5 "Segmentation fault", 0x70b9040 "/home/contrast/.config/GIMP/3.0/CrashLog/gimp-crash-1750142029.txt", 0x0, 0x7ffd2d909f10 "0", 0x0}
        timestamp = "0\000p+\000\000\000\000 s\021\036\274\177\000"
        config = <optimized out>
        eek_handled = 0
        debug_policy = GIMP_DEBUG_POLICY_FATAL
        iter = <optimized out>
        num_idx = <optimized out>
        i = 0
#3  0x00000000006693a8 in gimp_fatal_error (message=<optimized out>) at ../app/errors.c:206
#4  0x000000000066bf99 in gimp_sigfatal_handler (sig_num=11) at ../app/signals.c:206
#5  0x00007fbc1df9dfd0 in <signal handler called> () at /lib64/libc.so.6
#6  0x00007fbc1e005eb5 in free () at /lib64/libc.so.6
#7  0x00007fbc1f482c45 in g_free () at /lib64/libglib-2.0.so.0
#8  0x00007fbc1fa74300 in gimp_choice_desc_free (desc=0x2bf58450) at ../libgimpbase/gimpchoice.c:394
#9  gimp_choice_add (choice=0x2afc3010, nick=0x7fbc0ce1f13b "part2", id=1, label=0x7fbc0ce1f130 "NO CONTENT", help=<optimized out>) at ../libgimpbase/gimpchoice.c:207
        desc = <optimized out>
        duplicate = 0x2c557420 = {0x2bf58450}
#10 0x00000000006293fe in _gimp_param_spec_to_gp_param_def (pspec=0x6fbbe00, param_def=0x29ac6fa0) at ../app/plug-in/../../libgimp/gimpgpparams-body.c:488
        iter = <optimized out>
        enum_class = 0x6fbbdb0
        value = 0x7fbc0ce21118 <values+24>
        espec = 0x6fbbe00
        gespec = 0x6fbbe00
        choice = 0x2afc3010
        pspec_type = <optimized out>
        value_type = <optimized out>
#11 0x000000000062aff4 in gimp_value_to_gp_param (value=0x2bd157e0, param=0x29ac6f90, full_copy=<optimized out>) at ../app/plug-in/../../libgimp/gimpgpparams-body.c:1711
        type = <optimized out>
        type = <optimized out>
        _g_boolean_var_13 = <optimized out>
        _g_boolean_var_14 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        file = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        indexed_format = <optimized out>
        bpp = <optimized out>
        _g_boolean_var_15 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        color = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        indexed_format = <optimized out>
        bpp = <optimized out>
        _g_boolean_var_16 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        parasite = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        colors = <optimized out>
        __n = <optimized out>
        __s = <optimized out>
        __p = <optimized out>
        i = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        bytes = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        element_type = <optimized out>
        array_length = <optimized out>
        i = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __n = <optimized out>
        __s = <optimized out>
        __p = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        image = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        item = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        filter = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        display = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        resource = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        unit = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
#12 _gimp_value_array_to_gp_params (args=args@entry=0x2c585ca0, full_copy=full_copy@entry=0) at ../app/plug-in/../../libgimp/gimpgpparams-body.c:1748
        value = 0x2bd157e0
        params = 0x29ac6f90
        length = <optimized out>
        i = 0
#13 0x000000000062b057 in gimp_value_to_gp_param (value=0x2bc87cd8, param=0x2aefbd60, full_copy=<optimized out>) at ../app/plug-in/../../libgimp/gimpgpparams-body.c:1723
        array = 0x2c585ca0
        type = <optimized out>
        type = <optimized out>
        _g_boolean_var_13 = <optimized out>
        _g_boolean_var_14 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        file = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        indexed_format = <optimized out>
        bpp = <optimized out>
        _g_boolean_var_15 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        color = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        indexed_format = <optimized out>
        bpp = <optimized out>
        _g_boolean_var_16 = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        parasite = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        colors = <optimized out>
        __n = <optimized out>
        __s = <optimized out>
        __p = <optimized out>
        i = <optimized out>
        format = <optimized out>
        icc_length = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        bytes = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
        element_type = <optimized out>
        array_length = <optimized out>
        i = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __n = <optimized out>
        __s = <optimized out>
        __p = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __inst = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        image = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        item = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        filter = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        display = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        resource = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        unit = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        __val = <optimized out>
        __t = <optimized out>
        __r = <optimized out>
        array = <optimized out>
#14 _gimp_value_array_to_gp_params (args=args@entry=0x2bc4fa90, full_copy=full_copy@entry=0) at ../app/plug-in/../../libgimp/gimpgpparams-body.c:1748
        value = 0x2bc87cd8
        params = 0x2aefbd00
        length = <optimized out>
        i = 1
#15 0x000000000062d847 in gimp_plug_in_handle_proc_run (plug_in=0x2bffaf00, proc_run=0x2bcf3fc0) at ../app/plug-in/gimpplugin-message.c:618
        proc_return = {name = 0x2b0d0010 "gimp-drawable-filter-operation-get-pspecs", n_params = 2, params = 0x7fbc1f571280}
        proc_frame = 0x2bffb180
        procedure = <optimized out>
        return_vals = 0x2bc4fa90
        canonical = 0x2bdd89e0 "\270\375\320*"
        proc_name = <optimized out>
        args = <optimized out>
        error = 0x0
        proc_frame = <optimized out>
        canonical = <optimized out>
        proc_name = <optimized out>
        procedure = <optimized out>
        args = <optimized out>
        return_vals = <optimized out>
        error = <optimized out>
        _g_boolean_var_14 = <optimized out>
        _g_boolean_var_15 = <optimized out>
        proc_return = {name = <optimized out>, n_params = <optimized out>, params = <optimized out>}
#16 gimp_plug_in_handle_message (plug_in=0x2bffaf00, msg=<optimized out>) at ../app/plug-in/gimpplugin-message.c:128
#17 0x000000000061cb96 in gimp_plug_in_recv_message (channel=<optimized out>, cond=G_IO_IN, data=0x2bffaf00) at ../app/plug-in/gimpplugin.c:240
        msg = {type = 5, data = 0x2bcf3fc0}
        plug_in = <optimized out>
        got_message = <optimized out>
        plug_in = <optimized out>
        got_message = <optimized out>
        msg = {type = <optimized out>, data = <optimized out>}
        frame = <optimized out>
        progress = <optimized out>
#18 gimp_plug_in_recv_message (channel=<optimized out>, cond=G_IO_IN, data=0x2bffaf00) at ../app/plug-in/gimpplugin.c:196
        plug_in = 0x2bffaf00
        msg = {type = <optimized out>, data = <optimized out>}
        frame = <optimized out>
        progress = <optimized out>
#19 0x00007fbc1f48202c in g_main_context_dispatch_unlocked.lto_priv () at /lib64/libglib-2.0.so.0
#20 0x00007fbc1f4e3e20 in g_main_context_iterate_unlocked.isra () at /lib64/libglib-2.0.so.0
#21 0x00007fbc1f483503 in g_main_context_iteration () at /lib64/libglib-2.0.so.0
#22 0x00007fbc1f21428d in g_application_run () at /lib64/libgio-2.0.so.0
#23 0x00000000006688e9 in app_run (full_prog_name=0x6d6eb40 "/home/contrast/Applications/gimp_nde//bin/gimp-3.0", filenames=<optimized out>, alternate_system_gimprc=alternate_system_gimprc@entry=0x0, alternate_gimprc=alternate_gimprc@entry=0x0, session_name=<optimized out>, batch_interpreter=<optimized out>, batch_commands=0x0, quit=0, as_new=0, no_interface=0, no_data=<optimized out>, no_fonts=<optimized out>, no_splash=0, be_verbose=0, use_shm=1, use_cpu_accel=1, console_messages=0, use_debug_handler=0, show_playground=1, show_debug_menu=1, stack_trace_mode=GIMP_STACK_TRACE_QUERY, pdb_compat_mode=<optimized out>, backtrace_file=0x6d52ef0 "/home/contrast/.config/GIMP/3.0/CrashLog/gimp-crash-1750142029.txt") at ../app/app.c:309
        gimp = 0x6f4c460
        app = 0x6fe3a10
        default_folder = 0x0
        gimpdir = 0x6fe7f40
        abort_message = <optimized out>
        retval = 0
#24 0x00000000004acf35 in main (argc=<optimized out>, argv=<optimized out>) at ../app/main.c:793
        context = 0x6d6eb80
        error = 0x0
        abort_message = <optimized out>
        system_gimprc_file = 0x0
        user_gimprc_file = 0x0
        gimp_group = <optimized out>
        backtrace_file = 0x6d52ef0 "/home/contrast/.config/GIMP/3.0/CrashLog/gimp-crash-1750142029.txt"
        retval = <optimized out>
        i = <optimized out>
[Inferior 1 (process 778556) detached]

```
