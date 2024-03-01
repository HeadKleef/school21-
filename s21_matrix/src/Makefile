CC =gcc
CFLAGS = -Wall -Werror -Wextra
LIB = s21_matrix.c 

RM = rm -rf
CH = checkmk clean_mode=1 
###############################


################ определение ОС ####################
 UNAME  := $(shell uname -s)
ifeq ($(UNAME), Linux)
 	TFLAGS = -lpthread -pthread -lrt -lm -lsubunit
endif
ifeq ($(UNAME), Darwin)
	TFLAGS = -lcheck
endif
####################################################


 all: clean s21_matrix.a


####### тестирование с библеотекой CHECK #######

check.c: s21_matrix.a
	$(CH) auto_test/s21_matrix_test.check > $@
	clang-format -i check.c
	

test: 
	$(CC) $(TFLAGS) $(LIB)  check.c  -o test
	 ./test
	 $(RM) test
################################################


### тестирование с помощью файла .с ###
old_test: s21_matrix.a 
	$(CC) $(CFLAGS) $(TEST) $<  -o $@
	./old_test
#######################################


#### компиляция статической библиотеки ####
s21_matrix.a:
	ar rcs $@ $<
	ranlib $@
	rm $< 
	
###########################################


##################################GCOV_REPORT#####################################
gcov_report: s21_matrix.a check.c
	$(CC) $(CFLAGS) --coverage $(LIB)  check.c  $(TFLAGS) -lm -o gcov_test 
	

	./gcov_test
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	rm -rf *.o *.a  *.gch *.gcno test  gcov_test
##################################################################################


############## полная очистка ################ 
clean:
	$(RM) old_test test s21_matrix.a  *.gcda  *.gch *.gcno report test_report.info ret.txt 

clean_1:
	$(RM) old_test  test s21_matrix.a *.gcda ret.txt 
##############################################

############# ШПОРА ПО СОКРАЩЕНИЯМ ###################
# $@ - имя цели(целевого файла)                      #
# $< - имя первой зависимости(после двоеточия)       #
# $^ - имена всех зависимостей в цели (через пробел) #
######################################################