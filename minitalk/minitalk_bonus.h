/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saospina <saospina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:27:19 by saospina          #+#    #+#             */
/*   Updated: 2026/04/05 10:27:19 by saospina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "minitalk.h"

int	mt_bonus_send_char(pid_t server_pid, unsigned char c,
		volatile sig_atomic_t *ack_flag);
int	mt_bonus_send_message(pid_t server_pid, const char *msg,
		volatile sig_atomic_t *ack_flag);

#endif
