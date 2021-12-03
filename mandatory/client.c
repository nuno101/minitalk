/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:59 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/03 13:56:14 by nlouro           ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	while(msg[i] != '\0')
	{
		for(j = 7; j >= 0; --j)
		{
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(30);
		}
		i++;
	}
}

/*
 * parse user inputs as pid and message
 */
int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("\nERROR: wrong nr. of arguments. Call as:\nclient <pid> \"<message>\"\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("\nERROR: pid is not a number\n");
		return (2);
	}
	ft_printf("msg sent: %s\n", argv[2]);
	send_msg(server_pid, argv[2]);
	send_msg(server_pid, "\n");
	return (0);
}
