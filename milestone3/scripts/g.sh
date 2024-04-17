#!/bin/bash

while getopts ":mre" opt; do
  case ${opt} in
    m )
      make all
      # Replace the echo command with the command you want to run for -m flag
      ;;
    r )
      ./parser -input ./../tests/test.py -tac ./../out/gtac.txt -ast ./../out/ast.dot -csv ./../out/symtab.csv -asm ./../out/gx86.s  
      # Replace the echo command with the command you want to run for -r flag
      ;;
    e )
      gcc -c ./../out/gx86.s -o ./../out/gasm_test.o
      gcc ./../out/gasm_test.o -o ./../out/gexec
      ./../out/gexec
      # Replace the echo command with the command you want to run for -e flag
      ;;
    \? )
      echo "Invalid option: $OPTARG"
      ;;
    : )
      echo "Invalid option: $OPTARG requires an argument"
      ;;
  esac
done
