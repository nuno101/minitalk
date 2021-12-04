/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:59 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/04 09:55:24 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * send a message to a pid using signals
 * encode the message in 8 bit binary words
 * 1 becomes SIGUSR1
 * 0 becomes SIGUSR2
 */
void	send_msg(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(30);
			j--;
		}
		i++;
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message received. Bye!\n");
		exit(1);
	}
}

/*
 * parse user inputs as pid and message
 */
int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*client;
	char	eot;

	eot = 4;
	client = ft_itoa(getpid());
	ft_printf("Client PID: %s\n", client);
	if (argc != 3)
	{
		ft_printf("\nERROR: wrong args. Call as:\nclient <pid> \"<message>\"\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("\nERROR: pid is not a number\n");
		return (2);
	}
	ft_printf("Message sent: %s\n", argv[2]);
	send_msg(server_pid, client);
	send_msg(server_pid, ":");
	send_msg(server_pid, argv[2]);
	send_msg(server_pid, &eot);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
