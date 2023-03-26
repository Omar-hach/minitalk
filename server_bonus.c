/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:20:28 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/06 00:20:34 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minitalk.h"

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID=%d\n", pid);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &handler_b;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
