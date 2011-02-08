#!/bin/bash
# script	: test.sh
# discript	: test executable program in project by gdb
# author	: raiden
# date		: 2011-02-08
# version	: 0.1.0
#

EXEC=test
TEST_DIR=`pwd`/bin

echo executing $EXEC in $TEST_DIR

cd $TEST_DIR
gdb $EXEC $PARAM_LIST
