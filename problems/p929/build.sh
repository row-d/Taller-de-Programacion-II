#!/bin/bash
EXEC_EXT=''
EXEC_NAME="$(basename $PWD)$EXEC_EXT"
CPP_FILES=$(find . -name "*.cpp")
HPP_FILES=$(find . -name "*.hpp")

COMPILE_CMD="g++ -o $EXEC_NAME $CPP_FILES $HPP_FILES"
RUN_CMD="./$EXEC_NAME"

$COMPILE_CMD
$RUN_CMD