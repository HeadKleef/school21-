#!/bin/bash

GREP_FUNC_SUCCESS=0
GREP_FUNC_FAIL=0



 make

flags=(
   "-i"
   "-v"
   "-c"
   "-l"
   "-n"
   "-o"
)

patterns=(
    "int"
    "void"
    "flags"
    "_"
    "fi"
    "main"
    "argc"

)

for (( i = 0; i < 7 ; i++)); do
    for (( n = 0; n < 7 ; n++)); do
            ./s21_grep ${flags[i]} ${flags[n]} ${patterns[n]} flags.h > test_grep_2.txt
             grep ${flags[i]} ${flags[n]}  ${patterns[n]} flags.h > test_grep_3.txt
            

        if  cmp test_grep_2.txt test_grep_3.txt; #&& valgrind --track-origins=yes -q ./s21_grep ${flags[i]}  ${patterns[n]} flags.h > log.txt ;
        then 
            echo "flag :${flags[i]} ${flags[n]} pattern: ${patterns[n]} result :SUCCESS " 
            (( GREP_FUNC_SUCCESS++ ))
        else
             echo "flag :${flags[i]} ${flags[n]}  pattern: ${patterns[n]} result :FAIL"  
            (( GREP_FUNC_FAIL++ ))
        fi
        done
done

# for i in "${patterns[@]}"
# do
#   ./s21_grep -e $i  -e include flags.h > test_grep_2.txt
#      grep  -e $i -e include flags.h > test_grep_3.txt

#  if  cmp test_grep_2.txt test_grep_3.txt; #&& valgrind --track-origins=yes -q ./s21_grep ${flags[i]}  ${patterns[n]} flags.h > log.txt ;
#         then 
#             echo "flag : -e pattern: $i result :SUCCESS " 
#             (( GREP_FUNC_SUCCESS++ ))
#         else
#              echo "flag : -e pattern: $i result :FAIL"  
#             (( GREP_FUNC_FAIL++ ))
#         fi
#         done


echo "GREP_FUNC_SUCCESS = $GREP_FUNC_SUCCESS"
echo "GREP_FUNC_FAIL = $GREP_FUNC_FAIL"

#  rm test_grep_2.txt
#  rm test_grep_3.txt


cd ../grep/ 
make clean
cd ../auto_tests/


