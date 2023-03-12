/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arashido <avazbekrashidov6@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:45:41 by arashido          #+#    #+#             */
/*   Updated: 2023/03/12 17:47:22 by arashido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			sender(pid, argv[2][i]);
			i++;
		}
		sender(pid, '\n');
	}
	else
	{
		write (1, "Error: Wrong Format\n", 20);
		write (1, "Try: ./client <PID> <MESSAGE>\n", 30);
		return (1);
	}
	return (0);
}
