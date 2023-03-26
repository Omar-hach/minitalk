/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:57:06 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/07 19:58:52 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <signal.h>
# include "libft/libft.h"
# include "print/ft_printf.h"

void	character_sender_b(unsigned char letter, int pid);
void	handler_b(int binary, siginfo_t *info, void *n);

#endif
