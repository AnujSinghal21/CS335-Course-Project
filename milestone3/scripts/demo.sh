#!/bin/bash
make all

while getopts ":te" opt; do
  case ${opt} in
    t )
      echo "Running testcases"
      testcases=(1 2 3 4 5 6 7)
      for i in "${testcases[@]}"
        do
            echo "################# Running Testcase #$i ######################"
            echo "description: -------------------------------------------"
            head ./../tests/testcase$i.py -n 1
            echo "Compilation Results: ----------------------------------------"
            ./parser -input ./../tests/testcase$i.py -tac ./../out/tac_t$i.txt -csv ./../out/symtab_t$i.csv -asm ./../out/x86_t$i.s
            gcc -c ./../out/x86_t$i.s -o ./../out/asm_t$i.o
            gcc ./../out/asm_t$i.o -o ./../out/exec_t$i
            echo "Execution Results: ----------------------------------------"
            ./../out/exec_t$i
        done
      ;;
    e )
      echo "Showing error reporting"
      testcases=(1 2 3 4 5 6 7)
      for i in "${testcases[@]}"
        do
            echo "################# Running Erroneous Testcase #$i ######################"
            echo "description: -------------------------------------------"
            head ./../tests/error$i.py -n 1
            echo "Compilation Results: ----------------------------------------"
            ./parser -input ./../tests/error$i.py -tac ./../out/tac_e$i.txt -csv ./../out/symtab_e$i.csv -asm ./../out/x86_e$i.s
            # gcc -c ./../out/x86_t$i.s -o ./../out/asm_t$i.o
            # gcc ./../out/asm_t$i.o -o ./../out/exec_t$i
            # echo "Execution Results: ----------------------------------------"
            # ./../out/exec_t$i
        done
      ;;
    \? )
      echo "Invalid option: $OPTARG"
      ;;
    : )
      echo "Invalid option: $OPTARG requires an argument"
      ;;
  esac
done
