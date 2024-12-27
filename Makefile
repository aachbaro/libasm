CC = gcc
NASM = nasm
AR = ar
CFLAGS = -Wall -Wextra -Werror
ASFLAGS = -f elf64

NAME = libasm.a
SRCS = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.s
	$(NASM) $(ASFLAGS) $< -o $@

test: all
	gcc -g -o test main.c -L. -lasm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test

re: fclean all
