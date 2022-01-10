#!/usr/bin/env bash

gcc -DEVAL -O2 grader.c floppy.c -o floppy -lm
