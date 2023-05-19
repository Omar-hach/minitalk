/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:51:45 by ohachami          #+#    #+#             */
/*   Updated: 2023/02/07 19:52:46 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minitalk.h"

void	character_sender(char letter, int pid)
{
	char	*binary;
	int		i;

	binary = (char *)ft_calloc(9, sizeof(char));
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

int	main(int argc, char **argv)
{
	int		pid;
	int		len;
	char	*len_string;
	int		i;

	if (argc != 3)
		exit (1);
	if ((ft_strlen(argv[1]) == 2 && argv[1][0] == '-' && argv[1][1] == '1')
		|| (ft_strlen(argv[1]) == 1
		&& (argv[1][0] == '1' || argv[1][0] == '0')))
		exit (1);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	len_string = ft_itoa(len);
	i = -1;
	while (++i < len)
		character_sender(argv[2][i], pid);
	free(len_string);
	return (0);
}
