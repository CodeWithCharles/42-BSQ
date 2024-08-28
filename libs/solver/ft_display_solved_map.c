/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_solved_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:10:26 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 22:10:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_display_solved_map(t_map *m_dat)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < m_dat->nbr_line)
	{
		j = 0;
		while (j < m_dat->nbr_column)
		{
			write(1, &(m_dat->map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
