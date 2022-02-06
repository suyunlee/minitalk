/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suylee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:06:21 by suylee            #+#    #+#             */
/*   Updated: 2021/06/22 16:06:38 by suylee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
