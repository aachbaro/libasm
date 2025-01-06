NASM = nasm
AR = ar
ASFLAGS = -f elf64

NAME = libasm.a
SRCS = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.s
	$(NASM) $(ASFLAGS) $< -o $@

test: all
	@if [ -f main.c ]; then \
		clang -g -o test main.c -L. -lasm; \
	else \
		echo "main.c does not exist"; \
		exit 0; \
	fi

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test test_write.txt

re: fclean all
