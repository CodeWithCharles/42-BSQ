/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:25:40 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 19:25:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_compute_area(t_map *m_dat, unsigned int i, unsigned int j)
{
	int	min_val;

	if (m_dat->map[i][j] == m_dat->empty)
	{
		if (i == 0 || j == 0)
			m_dat->sols[i][j] = 1;
		else
		{
			min_val = ft_min_uint(m_dat->sols[i - 1][j], m_dat->sols[i][j - 1]);
			min_val = ft_min_uint(min_val, m_dat->sols[i - 1][j - 1]);
			m_dat->sols[i][j] = min_val + 1;
		}
	}
	else
		m_dat->sols[i][j] = 0;
	if (m_dat->sols[i][j] > m_dat->sol_max_area)
	{
		m_dat->sol_max_area = m_dat->sols[i][j];
		m_dat->sol_y = i;
		m_dat->sol_x = j;
	}
}

void	ft_retrieve_areas(t_map *m_dat)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < m_dat->nbr_line)
	{
		j = 0;
		while (j < m_dat->nbr_column)
		{
			ft_compute_area(m_dat, i, j);
			j++;
		}
		i++;
	}
}
