## How to build 

1. download and build dependencies 

    - Boost (v1.35.0): just download it from boost website and copy the `boost` subdirectory to `C:/Bitcoin/include` directory.

    - OpenSSL (v0.9.8h): download it from github's repo and copy include files to `C:/Bitcoin/include` directory, and copy the `libeay32.dll` file to default lib's dir (`C:/Bitcoin/lib`)

    - Berkeley DB (v4.7.25): download it from Oracle's website and build it using the following commands. 
        ```bash
        cd build_unix
        ../configure --enable-mingw --enable-cxx 
        ```
      If you are developing on Linux, you want to cross compile the bitcoin, then you need to run the following: 
        ```bash
        cd build_unix
        ../configure --enable-mingw --enable-cxx --host=i686-w64-mingw32
        ```
      
      After the compilation, you will get `libdb_cxx.a` which need to be copied into the default directory for libs (i.e. `C:/Bitcoin/lib`).

    - wxWidgets (v2.8.12) 
      
      ```bash
      cd build\msw\
      ../configure --with-msw --enable-debug --enable-debug_gdb --disable-shared
      make
      ```
      After this, you will get 
      ```
      libwxbase28d.a
      libwxbase28d_net.a
      ....
      libwxtiffd.a
      libwxzlibd.a
      ```