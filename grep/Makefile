CC = gcc
CFLAGS = -g -Wall -Werror -Wextra  
GREP =grep_test.c
OPT= flags_res.c
FLAGS = flags.c
NAME =s21_grep

all:
	$(CC) $(CFLAGS) $(GREP) $(FLAGS)  $(OPT) -o $(NAME)

s21_grep:
	
	$(CC) $(CFLAGS) $(GREP)  $(OPT) -o $(NAME)

clean:
	rm -rf $(NAME)