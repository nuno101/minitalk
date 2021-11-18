/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:38:59 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/18 10:37:26 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	send_msg(int pid, char *msg);

int	main(int argc, char *argv[])
{
	int	pid;
	int m;

	//printf("\ncmdline args=%d\n", argc);
	if (argc != 3)
	{
		printf("\nERROR: wrong nr. of arguments. Call as follows:\nclient <pid> \"<message>\"\n");
		return (1);
	}
	//printf("\ncmdline arg=%s", argv[1]);
	//pid = ft_atoi(argv[1]);
	pid = atoi(argv[1]);
	m = send_msg(pid, argv[2]);
	return (0);
}

int	send_msg(int pid, char *msg)
{
	printf("msg: %s\n", msg);
	//if (msg[0] == "1")
	if (1)
      kill(pid, SIGUSR1);
    else
      kill(pid, SIGUSR2);
	return (0);
}
