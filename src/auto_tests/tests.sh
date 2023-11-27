#!/bin/bash

CAT_FUNC_SUCCESS=0
CAT_FUNC_FAIL=0

touch test_cat_2.txt
touch test_cat_3.txt
touch log.txt

flags=(
    "-e"
    "-s"
    "-b"
    "-n"
    "-t"
    "-v"
    
)
gnu_flags_1=(
    "--number"
    "--number-nonblank"
    "--squeeze-blank"
)
gnu_flags_2=(
    "-n"
    "-b"
    "-s"
)

cd ../cat
make 
cd ../auto_tests

for i in "${flags[@]}"
do
./../cat/s21_cat $i test_cat_1.txt > test_cat_2.txt
cat $i test_cat_1.txt > test_cat_3.txt
 


if  cmp   test_cat_2.txt test_cat_3.txt; #  && valgrind --track-origins=yes -q ./../cat/s21_cat $i test_cat_1.txt > log.txt ;
then 
    echo "flag :$i result : SUCCESS " 
    (( CAT_FUNC_SUCCESS++ ))
else
    echo "flag :$i result :FAIL"
    (( CAT_FUNC_FAIL++ ))  
fi
done



for (( i = 0; i < 3 ; i++)); do
    ./../cat/s21_cat ${gnu_flags_1[i]} test_cat_1.txt > test_cat_2.txt

        cat ${gnu_flags_2[i]} test_cat_1.txt > test_cat_3.txt
        


if  cmp  test_cat_2.txt test_cat_3.txt; # && valgrind --track-origins=yes -q ./../cat/s21_cat ${gnu_flags_1[i]} test_cat_1.txt > log.txt; 
then 
    echo "flag :${gnu_flags_1[i]} result :SUCCESS " 
    (( CAT_FUNC_SUCCESS++ ))
else
    echo "flag :${gnu_flags_1[i]} result :FAIL"  
    (( CAT_FUNC_FAIL++ ))
fi
done

echo "CAT_FUNC_SUCCESS = $CAT_FUNC_SUCCESS"
echo "CAT_FUNC_FAIL = $CAT_FUNC_FAIL"

rm test_cat_2.txt
rm test_cat_3.txt
cd ../cat
make clean
cd ../auto_tests




GREP_FUNC_SUCCESS=0
GREP_FUNC_FAIL=0

cd ../grep
make
cd ../auto_tests

flags=(
   "-i"
   "-v"
   "-c"
   "-l"
   "-n"
   "-o"
)


patterns=(
    "i.t"
    "void"
    "flags"
    "_"
    "fi"
    "main"
    "argc"
  

)


for (( i = 0; i < 7 ; i++)); do
    for (( n = 0; n < 6 ; n++)); do
        for (( l = 0; l < 6; l++)) do
            ./../grep/s21_grep ${flags[i]} ${flags[n]} ${patterns[l]} ../grep/grep.c> test_grep_2.txt
             grep ${flags[i]} ${flags[n]}  ${patterns[l]} ../grep/grep.c > test_grep_3.txt
            

        if  cmp test_grep_2.txt test_grep_3.txt; # && valgrind --track-origins=yes -q ./../grep/s21_grep ${flags[i]}  ${patterns[n]} ../grep/flags.h > log.txt ;
        then 
            rm test_grep_2.txt
            rm test_grep_3.txt
            echo "flag :${flags[i]} ${flags[n]} pattern: ${patterns[l]} result :SUCCESS " 
            (( GREP_FUNC_SUCCESS++ ))
        else
             echo "flag :${flags[i]} ${flags[n]}  pattern: ${patterns[l]} result :FAIL"  
            (( GREP_FUNC_FAIL++ ))
        fi
                done
        done
done

for (( i = 0; i < 5 ; i++)); do
  ./../grep/s21_grep ${flags[i]} -f  pat_test.txt ../grep/grep.c > test_grep_2.txt
     grep ${flags[i]} -f  pat_test.txt ../grep/grep.c > test_grep_3.txt

 if  cmp test_grep_2.txt test_grep_3.txt; # && valgrind --track-origins=yes -q ./../grep/s21_grep  -f  pat_test.txt ../grep/flags.h > log.txt ;
        then 
            echo "flags : ${flags[i]} -f  result :SUCCESS " 
            (( GREP_FUNC_SUCCESS++ ))
        else
             echo "flags : ${flags[i]}  -f result :FAIL"  
            (( GREP_FUNC_FAIL++ ))
        fi
        done

for i in "${patterns[@]}"
do
  ./../grep/s21_grep -e $i  -e include ../grep/grep.c > test_grep_2.txt
     grep  -e $i -e include ../grep/grep.c > test_grep_3.txt

 if  cmp test_grep_2.txt test_grep_3.txt; #  && valgrind --track-origins=yes -q ./../grep/s21_grep -e $i  -e include ../grep/flags.h > log.txt ;
        then 
            echo "flag : -e pattern: $i result :SUCCESS " 
            (( GREP_FUNC_SUCCESS++ ))
        else
             echo "flag : -e pattern: $i result :FAIL"  
            (( GREP_FUNC_FAIL++ ))
        fi
        done


echo "CAT_FUNC_SUCCESS = $CAT_FUNC_SUCCESS"
echo "CAT_FUNC_FAIL = $CAT_FUNC_FAIL"
echo "GREP_FUNC_SUCCESS = $GREP_FUNC_SUCCESS"
echo "GREP_FUNC_FAIL = $GREP_FUNC_FAIL"

rm test_grep_2.txt
rm test_grep_3.txt
cd ../grep
make clean
cd ../auto_tests

cd ../cat
if clang-format -n *.c *.h
    then 
        echo "CLANG_TEST_CAT: DONE"
    else    
        echo "CLANG_TEST_CAT: FAIL"
fi
if cppcheck *.c *.h
    then 
        echo "CPP_TEST_CAT: DONE"
    else    
        echo "CPP_TEST_CAT: FAIL"
fi
cd ../grep
if clang-format -n *.c *.h
    then 
        echo "CLANG_TEST_GREP: DONE"
    else    
        echo "CLANG_TEST_GREP: FAIL"
fi
if cppcheck *.c *.h
    then 
        echo "CPP_TEST_GREP: DONE"
    else    
        echo "CPP_TEST_GREP: FAIL"
fi
cd ../grep
