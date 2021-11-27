/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/27 23:56:24 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <math.h>

void	binary2char(int bit)
{
	static int n;
	static int sum;

	//printf("binary2char\n");
	if (!n) // n = 0
	{
		//printf("setting n and sum \n");
		n = 8;
		sum = 0;
	}
	sum += pow(2, n - 1) * bit;
	//printf("bit: %i n: %i sum: %i \n", bit, n, sum);
	n--;
	if (n == 0)	
	{
		//printf("%i %c\n", sum, sum);
		write(1, &sum, 1);
	}
}

void handle_signal(int sig)
{
	//printf("handle_signal\n");
	if (sig == SIGUSR1)
		//putchar('1');
		binary2char(1);
	else if (sig == SIGUSR2)
		//putchar('0');
		binary2char(0);
}

int	main(void)
{
	ssize_t pid;

	pid = getpid();	
	printf("PID: %zi\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
