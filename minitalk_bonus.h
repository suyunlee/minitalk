/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:08:05 by suylee            #+#    #+#             */
/*   Updated: 2021/06/22 16:08:08 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define SIZE	1024

typedef struct	s_data
{
	char		str[SIZE + 1];
	size_t		bit;
}				t_data;

#endif
