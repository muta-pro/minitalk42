# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 13:14:48 by imutavdz          #+#    #+#              #
#    Updated: 2025/02/03 18:46:42 by imutavdz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
C_SRCS = sender.c
S_SRCS = receiver.c
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iheaders 
HDR = signal.h
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.c=.o)
all: client server
client: $(C_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT) -o client
server: $(S_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT) -o server 
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	rm -f $(C_OBJS) $(S_OBJS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(LIBFT) client server
re: fclean all