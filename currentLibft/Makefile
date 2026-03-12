# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 18:17:43 by saospina          #+#    #+#              #
#    Updated: 2026/03/11 19:26:17 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	$(MAKE) -C libft
	$(MAKE) -C libft/ft_printf
	$(MAKE) -C libft/get_next_line

bonus:
	$(MAKE) bonus -C libft
	$(MAKE) bonus -C libft/ft_printf
	$(MAKE) bonus -C libft/get_next_line

clean:
	$(MAKE) clean -C libft/get_next_line
	$(MAKE) clean -C libft/ft_printf
	$(MAKE) clean -C libft

fclean:
	$(MAKE) fclean -C libft/get_next_line
	$(MAKE) fclean -C libft/ft_printf
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re
