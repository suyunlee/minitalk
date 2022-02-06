/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:16:03 by suylee            #+#    #+#             */
/*   Updated: 2021/06/22 16:18:13 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_data	g_data;

void			handle_sigusr(int sig)
{
	(void)sig;
	if (sig == SIGUSR1)
	{
		g_data.str[g_data.bit / 8] |= (0x80 >> ((g_data.bit % 8)));
		g_data.bit++;
	}
	else if (sig == SIGUSR2)
	{
		g_data.str[g_data.bit / 8] ^= (0x80 >> ((g_data.bit % 8)));
		g_data.bit++;
	}
}

void			ft_set(void)
{
	int	enter;

	if (g_data.bit != 0 && (g_data.str[((g_data.bit - 1) / 8)] == 0
		|| ((g_data.bit) / 8) >= SIZE))
	{
		if ((g_data.bit / 8) < SIZE)
			enter = 1;
		else
			enter = 0;
		g_data.bit = 0;
		ft_putstr_fd(g_data.str, 1);
		if (enter)
			ft_putchar_fd('\n', 1);
		ft_memset(g_data.str, 0xFF, SIZE);
	}
}

int				main(int ac, char **av)
{
	pid_t pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("usage : ./server\n", 2);
		return (1);
	}
	else
	{
		pid = getpid();
		ft_putstr_fd("PID : ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
		g_data.bit = 0;
		g_data.str[SIZE] = '\0';
		ft_memset(g_data.str, 0xFF, SIZE);
		signal(SIGUSR1, handle_sigusr);
		signal(SIGUSR2, handle_sigusr);
		while (1)
			ft_set();
	}
}
