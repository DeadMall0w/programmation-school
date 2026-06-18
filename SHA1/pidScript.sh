#! /bin/bash

echo "Mon pid est : $$"
echo "Pid parent $PPID"
pid=$PPI
pstree $pid
