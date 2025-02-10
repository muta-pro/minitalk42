# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 13:14:48 by imutavdz          #+#    #+#              #
#    Updated: 2025/01/30 19:39:22 by imutavdz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
CORE_DIR = CORE
H_FILES = headers
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_base16.c ft_printf.c ft_printf_utils.c \
ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c ft_lstdelone_bonus.c \
ft_lstiter_bonus.c ft_lstlast_bonus.c \
ft_lstmap_bonus.c ft_lstnew_bonus.c \
ft_lstsize_bonus.c ft_base16.c ft_printf.c ft_printf_utils.c \
get_next_line.c get_next_line_utils.c
HDR = libft.h
INCLUDE = -I$(H_FILES)
OBJS = $(SRCS:$(CORE_DIR)/%.c=%.o)
# 	OBJS = $(SRCS:%.c=bin/%.o)
SRCS := $(addprefix $(CORE_DIR)/, $(SRCS))
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: $(CORE_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
# bin:
# 	mkdir bin
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all
