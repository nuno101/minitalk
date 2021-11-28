/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:59 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/28 11:07:35 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_msg(int pid, char *msg);

int	main(int argc, char *argv[])
{
	int	server_pid;
	int m;
	char *client;

	client = ft_itoa(getpid());
	printf("Client PID: %s\n", client);

	//printf("\ncmdline args=%d\n", argc);
	if (argc != 3)
	{
		printf("\nERROR: wrong nr. of arguments. Call as follows:\nclient <pid> \"<message>\"\n");
		return (1);
	}
	//printf("\ncmdline arg=%s", argv[1]);
	server_pid = ft_atoi(argv[1]);
	m = send_msg(server_pid, client);
	m = send_msg(server_pid, " : ");
	printf("msg: %s\n", argv[2]);
	m = send_msg(server_pid, argv[2]);
	m = send_msg(server_pid, "\n");
	return (0);
}

int	send_msg(int pid, char *msg)
{
	int i;
	int j;

	i = 0;
	//printf("msg: %s\n", msg);
	while(msg[i] != '\0')
	{
		for(j = 7; j >= 0; --j)
		{
			if (msg[i] & (1 << j))
				{
				//putchar('1');
				kill(pid, SIGUSR1);
				}
			else
				{
				//putchar('0');
				kill(pid, SIGUSR2);
				}
				usleep(30);
		}
		i++;
	}
	return (0);
}
