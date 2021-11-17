/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouro <nlouro@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:39:41 by nlouro            #+#    #+#             */
/*   Updated: 2021/11/17 21:56:44 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main()
{
	ssize_t pid;

	pid = getpid();	
	printf("PID: %zi\n", pid);
	//TODO: wait for SIGUSR1 or SIGUSR2

	getchar();
	return (0);
}
