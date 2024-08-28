/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_initialize_solutions_matrix.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:13:20 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 20:13:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

int	ft_struct_initialize_solutions(t_map *m_dat)
{
	unsigned int	i;

	m_dat->sols = malloc(sizeof(int *) * (m_dat->nbr_line));
	if (!m_dat->sols)
	{
		ft_struct_free_map(m_dat);
		return (0);
	}
	else
	{
		i = 0;
		while (i < m_dat->nbr_line)
		{
			m_dat->sols[i] = malloc(sizeof(int) * m_dat->nbr_column);
			if (!m_dat->sols[i])
			{
				ft_struct_free(m_dat);
				return (0);
			}
			i++;
		}
	}
	return (1);
}
