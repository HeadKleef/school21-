CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
GREP =s21_grep.c
CHECK=checks.c
OPT= options.c
NAME =s21_grep

all:
	$(CC) $(CFLAGS) $(GREP) $(CHECK) $(OPT) -o $(NAME)

s21_grep:
	
	$(CC) $(CFLAGS) $(GREP) $(CHECK) $(OPT) -o $(NAME)

clean:
	rm -rf $(NAME)