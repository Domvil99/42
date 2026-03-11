# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saospina <saospina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 20:00:00 by saospina          #+#    #+#              #
#    Updated: 2026/03/11 20:00:00 by saospina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	$(MAKE) -C libft
	$(MAKE) -C libft/ft_printf

bonus:
	$(MAKE) bonus -C libft
	$(MAKE) bonus -C libft/ft_printf

clean:
	$(MAKE) clean -C libft/ft_printf
	$(MAKE) clean -C libft

fclean:
	$(MAKE) fclean -C libft/ft_printf
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re
