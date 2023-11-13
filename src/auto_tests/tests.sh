#!/bin/bash

GREP_FUNC_SUCCESS=0
GREP_FUNC_FAIL=0

touch test__2.txt
touch test__3.txt




flags=(
   "-i"
   "-v"
   "-c"
   "-l"
   "-n"
    
)

patterns=(
    "in"
    "word"
    "AND"
    "5"
    "and"
)

for (( i = 0; i < 6 ; i++)); do
    for (( n = 0; n < 5 ; n++)); do
           ./s21_grep ${flags[i]} ${flags[n]} ${patterns[n]} test_grep_1.txt > test_grep_2.txt
            grep ${flags[i]} ${flags[n]}  ${patterns[n]} test_grep_1.txt > test_grep_3.txt
            

        if  cmp test_grep_2.txt test_grep_3.txt; # && valgrind --track-origins=yes -q ./s21_grep ${flags[i]}  ${patterns[n]} test_grep_1.txt > log.txt ;
        then 
            echo "flag :${flags[i]} ${flags[n]} pattern: ${patterns[n]} result :SUCCESS " 
            (( GREP_FUNC_SUCCESS++ ))
        else
             echo "flag :${flags[i]} ${flags[n]}  pattern: ${patterns[n]} result :FAIL"  
            (( GREP_FUNC_FAIL++ ))
        fi
        done
done


echo "GREP_FUNC_SUCCESS = $GREP_FUNC_SUCCESS"
echo "GREP_FUNC_FAIL = $GREP_FUNC_FAIL"

# rm test_grep_2.txt
# rm test_grep_3.txt



