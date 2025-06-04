# FTCJTAG

A small cross-platform implementation of FTDI's [FTCJTAG](http://www.ftdichip.com/Support/SoftwareExamples/MPSSE/FTCJTAG.htm) library.  The original sources targeted Windows only.  This repository contains changes enabling 64‑bit Linux builds.

## Requirements

* CMake 2.6 or later
* A C++ compiler (tested with GCC)
* FTDI's D2XX runtime library to link applications that use `libftcjtag`

An abbreviated `ftd2xx.h` header is included in the repository.  If you have the
full D2XX SDK installed, you can point the build system at your copy instead.

## Building on Linux (64‑bit)

```bash
# obtain the source and enter the directory
mkdir build && cd build

# configure.  Provide the location of FTD2XX headers if needed
cmake .. -DFTD2XX_INCLUDE_DIR=..

# build static and shared libraries
cmake --build .
```

The build produces `libftcjtag.so` and `libftcjtag.a` in the `build` directory.
Link your applications against these libraries **and** against FTDI's D2XX
library.

To install the libraries system wide you can run:

```bash
sudo cmake --install .
```

## License

See `License.txt` for licensing information from FTDI.
