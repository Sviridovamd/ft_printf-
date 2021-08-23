C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = mylibft

INCLUDES = includes

SRC = hexa_write.c pointer_write.c string_write.c char_write.c	write_integer.c write_uinteger.c ft_printf.c for_hex.c for_uinteger.c for_struct.c for_printf.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(C) $(FLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp mylibft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)


re: fclean all
