/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:59 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/30 15:22:11 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *msg);
void	handle_signal(int sig);

int	main(int argc, char *argv[])
{
	int	server_pid;

	//printf("\ncmdline args=%d\n", argc);
	if (argc != 3)
	{
		printf("\nERROR: wrong nr. of arguments. Call as:\nclient <pid> \"<message>\"\n");
		return (1);
	}
	//printf("\ncmdline arg=%s", argv[1]);
	server_pid = ft_atoi(argv[1]);
	printf("msg: %s\n", argv[2]);
	send_msg(server_pid, argv[2]);
	send_msg(server_pid, "\n");
	return (0);
}

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
}
