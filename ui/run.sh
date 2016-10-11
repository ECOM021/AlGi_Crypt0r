#!/bin/bash
g++ `pkg-config gtk+-3.0 --cflags` test.cpp -o hello_world_gtk `pkg-config gtk+-3.0 --libs`

