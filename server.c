/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/27 21:32:44 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <math.h>

void	binary2char(int bit)
{
	static ssize_t n;
	static ssize_t sum;

	//printf("binary2char\n");
	if (!n)
		n = 7;
	if (!sum)
		sum = 0;
	if (n >= 0)
	{
		sum += pow(2, n) * bit;
		printf("bit: %i n: %zi sum: %zi \n", bit, n, sum);
		if (n < 0)
		{
			printf("%zi", sum);
			printf("%zd", sum);
			n = 7;
			sum = 0;
		}
		n--;
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
