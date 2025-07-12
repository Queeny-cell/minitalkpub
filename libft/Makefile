# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 13:48:25 by mapodevi          #+#    #+#              #
#    Updated: 2025/07/05 11:25:00 by mapodevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
	ft_calloc.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
	ft_striteri.c ft_itoa.c ft_split.c ft_printf.c ft_putstr.c ft_putptr.c \
	ft_putnbr.c ft_putnbr_unsigned.c ft_puthex.c ft_putchar.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJECTS = $(SOURCES:%.c=%.o)

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS:%.c=%.o)

all : $(NAME)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(BONUS_OBJS) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJS)

.PHONY : all clean fclean re