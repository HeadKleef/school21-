#!/bin/bash

flags=(
    "-e"
    "-s"
    "-b"
    "-n"
    "-t"
    
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

for i in "${flags[@]}"
do
./s21_cat $i test_1.txt > test_2.txt
cat $i test_1.txt > test_3.txt
file_1=test_2.txt
file_2=test_3.txt

if  diff -w  test_2.txt test_3.txt  ;
then 
    echo "flag :$i result :The files same " 
else
    echo "flag :$i result :The files different"  
fi
done



for (( i = 0; i < 3 ; i++)); do
    ./s21_cat ${gnu_flags_1[i]} test_1.txt > test_2.txt
    
        cat ${gnu_flags_2[i]} test_1.txt > test_3.txt
file_1=test_2.txt
file_2=test_3.txt
if  diff -w  test_2.txt test_3.txt  ;
then 
    echo "flag :${gnu_flags_1[i]} result :The files same " 
else
    echo "flag :${gnu_flags_1[i]} result :The files different"  
fi
done
