CC =gcc
CFLAGS = -Wall -Werror -Wextra
TEST = s21_string_test.c 
LIB = s21_string.c 
RM = rm -rf
CH = checkmk clean_mode=1 

################определение ОС####################
UNAME  := $(shell uname -s)
ifeq ($(UNAME), Linux)
	TFLAGS = -lpthread -pthread -lrt -lm -lsubunit
endif
ifeq ($(UNAME), Darwin)
	TFLAGS = -lcheck
endif
##################################################


all: s21_string.a

check.c: s21_string.a
	$(CH) s21_string_test.check > $@
	$(CC) $(TFLAGS) $(LIB) $@ -o check


s21_string.a:
	$(CC) -c $(LIB) -o s21_string.o
	ar rcs $@ *.o
	ranlib $@
	$(RM) *.o

testing: check.c #s21_string.a 
#	$(CC) $(CFLAGS) $(TEST) $<  -o $@
#	 ./$@
#	 $(RM) $@
	 ./check

test: s21_string.a 
	$(CC) $(CFLAGS) $(TEST) $<  -o $@

clean:
	$(RM) test s21_string.a check check.c 

############# ШПОРА ПО СОКРАЩЕНИЯМ ###################
# $@ - имя цели(целевого файла)                      #
# $< - имя первой зависимости(после двоеточия)       #
# $^ - имена всех зависимостей в цели (через пробел) #
######################################################