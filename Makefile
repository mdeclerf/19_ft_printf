# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 15:29:26 by mdeclerf          #+#    #+#              #
#    Updated: 2021/06/14 12:39:54 by mdeclerf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	gcc

CFLAGS	=	-c -Wall -Wextra -Werror

INCLUDE = -I./includes

SRCS	=	utils/ft_affichage.c					\
			utils/ft_affichage_utils.c				\
			utils/ft_atoi.c							\
			utils/ft_flags_c.c						\
			utils/ft_flags_i.c						\
			utils/ft_flags_p.c						\
			utils/ft_flags_s.c						\
			utils/ft_flags_u.c						\
			utils/ft_flags_u_back.c					\
			utils/ft_flags_p_back.c					\
			utils/ft_flags_s_back.c					\
			utils/ft_flags_x.c						\
			utils/ft_flags_pourcent.c				\
			utils/ft_strlen.c						\
			utils/ft_structure_init.c				\
			utils/ft_structure_flags.c				\
			utils/ft_structure_flags_utils.c		\
			utils/ft_treat_flags.c					\
			utils/ft_va_len.c						\
			utils/ft_va_storage.c					\
			utils/ft_wildcard.c						\
			utils/ft_puthex.c						\
			utils/ft_putaddress.c					\
			ft_printf.c								\

$(NAME):	
			@$(CC) $(CFLAGS) $(INCLUDE) $(SRCS)
			@ar -rc $(NAME) *.o

all :		$(NAME)

clean:		
			@rm -f *.o

fclean:		clean
			@rm -f $(NAME)

re:			fclean all
