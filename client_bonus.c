/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:09:24 by suylee            #+#    #+#             */
/*   Updated: 2021/06/24 13:11:38 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	transmit_end(int pid, int i)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
		usleep(100);
	}
	if (i % SIZE == SIZE - 1)
		transmit_end(pid, i + 1);
}

static void	transmit_message(int pid, char *msg)
{
	int	i;
	int	bit;

	i = 0;
	while (msg[i])
	{
		bit = -1;
		while (++bit < 8)
		{
			if ((msg[i] & (0x80 >> bit)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR1) == -1)
				exit(1);
			usleep(30);
		}
		i++;
	}
	transmit_end(pid, i);
	if (msg[i] == '\0')
		ft_putstr_fd("succes reception\n", 1);
	else
		ft_putstr_fd("failed reception\n", 1);
}

int			main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("usage : ./client [pid] [msg]\n", 2);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_putstr_fd("Unknow PID\n", 2);
		return (1);
	}
	transmit_message(pid, av[2]);
	return (0);
}
