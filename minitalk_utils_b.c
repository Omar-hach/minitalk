/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:11:48 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/07 03:11:54 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minitalk.h"

void	character_sender_b(unsigned char letter, int pid)
{
	unsigned char	*binary;
	int				i;

	binary = (unsigned char *)ft_calloc(8, 1);
	if (!binary)
		exit(1);
	i = 8;
	while (i--)
	{
		binary[i] = letter % 2 + '0';
		letter = letter / 2;
	}
	while (*binary)
	{
		usleep(250);
		if (*binary == '1')
			kill(pid, SIGUSR1);
		else if (*binary == '0')
			kill(pid, SIGUSR2);
		binary++;
	}
	free(binary - 8);
}

int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent--)
		result *= base;
	return (result);
}

void	function_b(int	*i, int *message, int client_pid)
{
	int		len;
	int		ascii_code;
	char	*back_message;

	*i = -1;
	back_message = NULL;
	len = 0;
	ascii_code = 0;
	while (++(*i) < 8)
		ascii_code += power(2, 7 - *i) * message[*i];
	if (!ascii_code)
		kill(client_pid, SIGUSR1);
	else
		ft_printf("%c", ascii_code);
	*i = 0;
}

void	handler_b(int binary, siginfo_t *info, void *n)
{
	static int		message[8];
	static int		i;
	static int		client_pid;

	(void)n;
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		i = 0;
	}
	if (i < 8)
	{
		if (binary == SIGUSR1)
			message[i] = 1;
		else
			message[i] = 0;
		i++;
	}
	if (i == 8)
		function_b(&i, message, client_pid);
}
