#!/bin/bash
make
./retirement > retirement.txt
diff -y retirement.txt retirement_ans.txt > diff.txt
emacs diff.txt
