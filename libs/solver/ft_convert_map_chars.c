/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_map_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:04:34 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 22:04:34 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_convert_map_chars(t_map *m_dat)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	sol_origin_y;
	unsigned int	sol_origin_x;

	sol_origin_y = m_dat->sol_y - m_dat->sol_max_area + 1;
	sol_origin_x = m_dat->sol_x - m_dat->sol_max_area + 1;
	i = 0;
	while (i < m_dat->nbr_line)
	{
		j = 0;
		while (j < m_dat->nbr_column)
		{
			if ((i >= sol_origin_y && i <= m_dat->sol_y)
				&& (j >= sol_origin_x && j <= m_dat->sol_x))
				m_dat->map[i][j] = m_dat->filler;
			j++;
		}
		i++;
	}
}
