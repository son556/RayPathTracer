# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:49:37 by taehyeon          #+#    #+#              #
#    Updated: 2022/12/21 20:45:11 by taehyeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_strncmp.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(OBJS) $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	rm -f all bonus $(NAME)
	ar rc $(NAME) $(OBJS)
	touch all

bonus: $(OBJS_BONUS)
	rm -f all bonus $(NAME)
	ar rc $(NAME) $(OBJS_BONUS)
	touch bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) all bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
