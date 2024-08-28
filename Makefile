COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes

SOURCES = $(wildcard ./libs/*.c) \
			$(wildcard ./libs/**/*.c) \
			$(wildcard ./libs/**/**/*.c) \
			$(wildcard ./main.c)

OBJECTS = $(SOURCES:.c=.o)

NAME = BSQ

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
