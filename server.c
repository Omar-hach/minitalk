/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:53:27 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/07 19:56:53 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minitalk.h"

int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent--)
		result *= base;
	return (result);
}

void	bit_t_word(siginfo_t *info, int *client_pid, int *i)
{
	if (info->si_pid != *client_pid)
	{
		*client_pid = info->si_pid;
		*i = 0;
	}
}

void	handler(int binary, siginfo_t *info, void *n)
{
	static int	message[8];
	int			ascii_code;
	static int	i;
	static int	client_pid;

	(void)n;
	ascii_code = 0;
	if (info->si_pid != client_pid)
		bit_t_word(info, &client_pid, &i);
	if (i < 8)
	{
		if (binary == SIGUSR1)
			message[i] = 1;
		else
			message[i] = 0;
		i++;
	}
	if (i == 8)
	{
		i = -1;
		while (++i < 8)
			ascii_code += power(2, 7 - i) * message[i];
		ft_printf("%c", ascii_code);
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID=%d\n", pid);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &handler;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
	}
	return (0);
}
