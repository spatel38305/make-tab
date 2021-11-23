#!/usr/bin/env bash
gcc -o make-tab.so make-tab.c $(yed --print-cflags) $(yed --print-ldflags)
