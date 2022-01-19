#!/bin/bash

if [ ! -n "$1" ]; then
  echo "parameter subtask nicht gesetzt"
  echo "usage: $0 <subtask>"
  echo "subtask 1.1 : 1"
  echo "subtask 1.2 : 2"
  echo "subtask 1.3 : 3"
  echo "subtask 1.4 : 4"
  echo "subtask 2.2 : 5"
  echo "subtask 2.2 : 6"
  exit 1
fi

if (($1 >= 1 && $1 <= 6)); then
  gcc -std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter -Iinclude Main_$1.c Sort.c Helper.c -o sort$1 && "./sort$1"
else
  echo "Invalid parameter."
   echo "usage: $0 <subtask>"
  echo "subtask 1.1 : 1"
  echo "subtask 1.2 : 2"
  echo "subtask 1.3 : 3"
  echo "subtask 1.4 : 4"
  echo "subtask 2.2 : 5"
  echo "subtask 2.2 : 6"
fi
