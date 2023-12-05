COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
FILENAME1="1.txt"
FILENAME2="2.txt"
FILENAME3="3.txt"
echo "" > log.txt
SHABLON="123"
SHABLON2="abc"

cd ../grep
make
cd ../auto_tests


echo "----------------1---------------------------------------------------"
for i in  -c -l -n -i -h -s -o
do
          TEST1="$i $SHABLO $FILENAME1 $FILENAME2 $FILENAME3"
          ./../grep/s21_grep $TEST1 > s21_grep$i.txt
          grep $TEST1 > grep$i.txt
          DIFF_RES="$(diff -s s21_grep$i.txt grep$i.txt)"
          if [ "$DIFF_RES" == "Files s21_grep$i.txt and grep$i.txt are identical" ]
            then
              echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL $TEST1"
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep$i.txt grep$i.txt

done


echo "--------------------------2-----------------------------------------"
for i in -v -c -l -n -i -h -s -o
do
  for j in -v -c -l -n -i -h -s -o
  do
        if [ $i != $j ]
        then
            TEST1="$i $j $FILENAME1 $FILENAME2 $FILENAME3"
            echo "$TEST1"
            ./../grep/s21_grep $TEST1 > s21_grep${i}${j}.txt
            grep $TEST1 > grep${i}${j}.txt
            DIFF_RES="$(diff -s s21_grep${i}${j}.txt grep${i}${j}.txt)"
            if [ "$DIFF_RES" == "Files s21_grep${i}${j}.txt and grep${i}${j}.txt are identical" ]
              then
                echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
              else
                echo "FAIL $TEST1"
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
            rm s21_grep${i}${j}.txt grep${i}${j}.txt
        fi
          
  done
done
SHABLON
###################################
echo "----------------------------3--------------------------------------"
for i in  -c -l -n -i -h -s -o
do
          TEST1="$i $SHABLON $FILENAME1 $FILENAME2 $FILENAME3"
          echo "$TEST1" 
          ./../grep/s21_grep $TEST1 > s21_grep$i.txt
          grep $TEST1 > grep$i.txt
          DIFF_RES="$(diff -s s21_grep$i.txt grep$i.txt)"
          if [ "$DIFF_RES" == "Files s21_grep$i.txt and grep$i.txt are identical" ]
            then
              echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL $TEST1"
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          #rm s21_grep$i.txt grep$i.txt

done


echo "---------------------------4---------------------------------------"
for i in -v -c -l -n -i -h -s -o
do
  for j in -v -c -l -n -i -h -s -o
  do
        if [ $i != $j ]
        then
            TEST1="$i $vj $SHABLON $FILENAME1 $FILENAME2 $FILENAME3"
            echo "$TEST1"
            ./../grep/s21_grep $TEST1 > s21_grep${i}${j}.txt
            grep $TEST1 > grep${i}${j}.txt
            DIFF_RES="$(diff -s s21_grep${i}${j}.txt grep${i}${j}.txt)"
            if [ "$DIFF_RES" == "Files s21_grep${i}${j}.txt and grep${i}${j}.txt are identical" ]
              then
                echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
              else
                echo "FAIL $TEST1"
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
            rm s21_grep${i}${j}.txt grep${i}${j}.txt
        fi
          
  done
done

SHABLON2
###################################
echo "--------------------------5-----------------------------------------"
for i in  -c -l -n -i -h -s -o
do
          TEST1="$i $SHABLON2 $FILENAME1 $FILENAME2 $FILENAME3"
          echo "$TEST1" # 
          ./../grep/s21_grep $TEST1 > s21_grep$i.txt
          grep $TEST1 > grep$i.txt
          DIFF_RES="$(diff -s s21_grep$i.txt grep$i.txt)"
          if [ "$DIFF_RES" == "Files s21_grep$i.txt and grep$i.txt are identical" ]
            then
              echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL $TEST1"
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep$i.txt grep$i.txt

done
  


echo "-----------------------------6--------------------------------------"
for i in -v -c -l -n -i -h -s -o
do
  for j in -v -c -l -n -i -h -s -o
  do
        if [ $i != $j ]
        then
            TEST1="$i $j $SHABLON2 $FILENAME1 $FILENAME2 $FILENAME3"
            echo "$TEST1"
            ./../grep/s21_grep $TEST1 > s21_grep${i}${j}.txt
            grep $TEST1 > grep${i}${j}.txt
            DIFF_RES="$(diff -s s21_grep${i}${j}.txt grep${i}${j}.txt)"
            if [ "$DIFF_RES" == "Files s21_grep${i}${j}.txt and grep${i}${j}.txt are identical" ]
              then
                echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
              else
                echo "FAIL $TEST1"
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
            rm s21_grep${i}${j}.txt grep${i}${j}.txt
        fi
          
  done
done

echo "------------------------------7-------------------------------------"
for i in  -c -l -n -i -h -s -o
do
          TEST1="$i \"$SHABLON5\" $FILENAME1 $FILENAME2 $FILENAME3"
          echo "$TEST1" # 
          ./../grep/s21_grep $TEST1 > s21_grep$i.txt
          grep $TEST1 > grep$i.txt
          DIFF_RES="$(diff -s s21_grep$i.txt grep$i.txt)"
          if [ "$DIFF_RES" == "Files s21_grep$i.txt and grep$i.txt are identical" ]
            then
              echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL $TEST1"
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep$i.txt grep$i.txt

done

echo "-----------------------------8--------------------------------------"
for i in  -c -l -n -i -h -s 
do
          TEST1="$i -f pattern.txt $FILENAME1 $FILENAME2 $FILENAME3"
          echo "$TEST1" # 
          ./../grep/s21_grep $TEST1 > s21_grep$i.txt
          grep $TEST1 > grep$i.txt
          DIFF_RES="$(diff -s s21_grep$i.txt grep$i.txt)"
          if [ "$DIFF_RES" == "Files s21_grep$i.txt and grep$i.txt are identical" ]
            then
              echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL $TEST1"
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep$i.txt grep$i.txt

done

echo "----------------------------10---------------------------------------"
for i in -v -c -l -n -i -h -s -o
do
  for j in -v -c -l -n -i -h -s -o
  do
        if [ $i != $j ]
        then
            TEST1="$i $j a $FILENAME1 $FILENAME2 $FILENAME3"
            echo "$TEST1"
            ./../grep/s21_grep $TEST1 > s21_grep${i}${j}.txt
            grep $TEST1 > grep${i}${j}.txt
            DIFF_RES="$(diff -s s21_grep${i}${j}.txt grep${i}${j}.txt)"
            if [ "$DIFF_RES" == "Files s21_grep${i}${j}.txt and grep${i}${j}.txt are identical" ]
              then
                echo "SUCCES $TEST1"
              (( COUNTER_SUCCESS++ ))
              else
                echo "FAIL $TEST1"
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
           rm s21_grep${i}${j}.txt grep${i}${j}.txt
        fi
          
  done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"