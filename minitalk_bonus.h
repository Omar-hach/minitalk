/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:18:01 by ohachami          #+#    #+#             */
/*   Updated: 2023/05/19 18:18:03 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <sys/types.h>
# include <signal.h>
# include "libft/libft.h"
# include "libft/print/ft_printf.h"

void	character_sender_b(unsigned char letter, int pid);
void	handler_b(int binary, siginfo_t *info, void *n);

#endif
