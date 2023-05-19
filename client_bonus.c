/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:21:07 by ohachami          #+#    #+#             */
/*   Updated: 2023/03/06 00:21:08 by ohachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int					pid;
	int					len;
	char				*len_string;
	int					i;
	struct sigaction	action;

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
	while (++i < len + 1)
		character_sender_b(argv[2][i], pid);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &handler_b;
	i = sigaction(SIGUSR1, &action, NULL);
	if (!i)
		write(1, "the message was delivred\n", 25);
	free(len_string);
	return (0);
}
