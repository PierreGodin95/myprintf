##
## EPITECH PROJECT, 2023
## makefile
## File description:
## In your Makefile you must list all of the C files separatly (no *.c),
## compile them, and use the result to generate the libmy.a library.
##

SRC2 =	bonus/mini_printf_tests.c

NAME =	libmy.a

SNAME =	unit_tests

LDFLAGS = -L lib/my/ -lmy

CPPFLAGS = -I include/

TESTFLAGS = --coverage -lcriterion

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
	$(MAKE) -C lib/my/

clean:
	$(MAKE) clean -C lib/my/

fclean:
	$(MAKE) fclean -C lib/my/

re: fclean all
unit_test:
	$(MAKE) unit_test -C lib/my/

tests_run:
	$(MAKE) tests_run -C lib/my/

.PHONY:	all clean fclean re unit_test tests_run
