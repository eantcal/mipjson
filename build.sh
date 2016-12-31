#!/bin/sh

chmod +x ./autogen.sh
./autogen.sh

rm -rf build
mkdir build && cd build && ../configure --prefix `readlink -f ../build` && make install

