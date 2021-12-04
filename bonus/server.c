/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/12/04 12:46:19 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

int	powerof2(int n)
{
	int	i;
	int	power;

	power = 1;
	i = 1;
	while (i <= n - 1)
	{
		power = power * 2;
		i++;
	}
	return (power);
}

int	handle_char(int pid_found, int ascii_code)
{
	if (pid_found == 0)
	{
		if (ascii_code == 58)
			pid_found = 1;
		else
			g_pid = g_pid * 10 + (ascii_code - 48);
	}
	else if (ascii_code == 4)
	{
		write(1, "\n", 1);
		usleep(100);
		kill(g_pid, SIGUSR1);
		g_pid = 0;
	}
	else
		write(1, &ascii_code, 1);
	return (pid_found);
}

/*
 * decode 8 bit binary encoded characters
 * after each 8 bits received print the decoded character
 */
void	binary2char(int bit)
{
	static int	n;
	static int	sum;
	static int	pid_found;

	if (!n)
	{
		if (!g_pid)
			pid_found = 0;
		n = 8;
		sum = 0;
	}
	sum += powerof2(n) * bit;
	n--;
	if (n == 0)
		pid_found = handle_char(pid_found, sum);
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
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
