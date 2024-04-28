#!/bin/bash

while getopts ":mre" opt; do
  case ${opt} in
    m )
      make all
      # Replace the echo command with the command you want to run for -m flag
      ;;
    r )
      ./parser -input ./../out/test.py -tac ./../out/tac_anuj.txt -ast ./../out/ast.dot -csv ./../out/symtab.csv -asm ./../out/x86_anuj.s  
      # Replace the echo command with the command you want to run for -r flag
      ;;
    e )
      gcc -c ./../out/x86_anuj.s -o ./../out/asm_test.o
      gcc ./../out/asm_test.o -o ./../out/anuj_exec
      ./../out/anuj_exec
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
