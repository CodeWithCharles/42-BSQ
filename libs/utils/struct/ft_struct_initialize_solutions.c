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

t_map	*ft_struct_initialize_solutions(t_map *m_dat)
{
	unsigned int	i;

	m_dat->sols = malloc(sizeof(int *) * (m_dat->nbr_line * m_dat->nbr_column));
	if (!m_dat->sols)
		ft_print_error("Error: allocating memory to solutions\n");
	else
	{
		i = 0;
		while (i < m_dat->nbr_column)
		{
			m_dat->sols[i] = malloc(sizeof(int) * m_dat->nbr_column);
			if (!m_dat->sols[i])
			{
				ft_print_error("Error: allocating memory to solutions rows.\n");
				ft_struct_free(m_dat);
				return (NULL);
			}
			i++;
		}
	}
	return (m_dat);
}
