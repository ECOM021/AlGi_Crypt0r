#!/bin/bash

mkdir -p ./build

g++ $(find ./* | grep .cpp)                                     \
    $(find ./* | grep .hpp)                                     \
    -w -std=c++0x -lm                                           \
   `pkg-config --cflags --libs gtkmm-3.0`                       \
   -o ./build/AlGi_Crypt0r