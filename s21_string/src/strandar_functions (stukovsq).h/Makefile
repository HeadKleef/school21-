########## сокращения ##########
CC =gcc
CFLAGS = -Wall -Werror -Wextra
TEST = s21_string_test.c 
LIB = s21_string.c 
LIBEX = s21_string_ex.c
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

all: s21_string.a

## тестирование с библеотекой CHECK ###
check.c: s21_string.a
	$(CH) s21_string_test.check > $@
	$(CC) $(TFLAGS) $(LIB) $@ -o check

test: check.c 
	 ./check
#######################################


### тестирование с помощью файла .с ###
old_test: s21_string.a 
	$(CC) $(CFLAGS) $(TEST) $<  -o $@
	./old_test
#######################################


## компиляция статической библиотеки ##
s21_string.a: s21_string.o s21_string_ex.o
	ar rcs $@ $< s21_string_ex.o
	ranlib $@
	rm $<

s21_string.o: $(LIB)
	$(CC) -c $(LIB) -o $@
s21_string_ex.o: $(LIBEX)
	$(CC) -c $(LIBEX) -o $@
	
#######################################



############ полная очистка ############## 
clean:
	$(RM) old_test s21_string.a check check.c 
##########################################


############# ШПОРА ПО СОКРАЩЕНИЯМ ###################
# $@ - имя цели(целевого файла)                      #
# $< - имя первой зависимости(после двоеточия)       #
# $^ - имена всех зависимостей в цели (через пробел) #
######################################################