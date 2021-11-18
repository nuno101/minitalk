/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/18 10:38:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void handle_signal(int sig)
{
	if (sig == SIGUSR1)
		printf("SIGUSR1\n");
	else if (sig == SIGUSR2)
		printf("SIGUSR2\n");
}

int	main()
{
	ssize_t pid;

	pid = getpid();	
	printf("PID: %zi\n", pid);
	while (1)
	{
		pause();
		printf("signal received...\n");"
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
	return (0);
}
