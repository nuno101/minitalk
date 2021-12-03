/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/03 15:21:25 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * decode 8 bit binary encoded characters
 * after each 8 bits received print the decoded character
 */
void	binary2char(int bit)
{
	static int	n;
	static int	sum;
	int			i;
	int			power;

	if (!n)
	{
		n = 8;
		sum = 0;
	}
	power = 1;
	i = 1;
	while (i <= n - 1)
	{
		power = power * 2;
		i++;
	}
	sum += power * bit;
	n--;
	if (n == 0)
		write(1, &sum, 1);
}

/*
 * pass received signals to binary2char for decoding
 * SIGUSR1 is 1
 * SIGUSR2 is 0
 */
void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		binary2char(1);
	else if (sig == SIGUSR2)
		binary2char(0);
}

/*
 * print own PID and wait for signals USR1 and USR2
 */
int	main(void)
{
	ssize_t	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
