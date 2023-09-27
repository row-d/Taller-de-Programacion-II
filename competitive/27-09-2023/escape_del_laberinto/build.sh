#!/bin/bash
EXEC_EXT='.out'
EXEC_NAME="solution$EXEC_EXT"
CPP_FILES=$(find . -name "*.cpp")
HPP_FILES=$(find . -name "*.hpp")

COMPILE_CMD="g++ -Wall -o $EXEC_NAME $CPP_FILES $HPP_FILES"
RUN_CMD="./$EXEC_NAME"

$COMPILE_CMD
$RUN_CMD
# diff --color -u output.txt expected.txt