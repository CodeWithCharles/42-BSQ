/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:39:39 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:33:54 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	ft_map_to_struct(char **m_in, t_map *m_dat, int nbr_line)
{
	int	*infos;
	int	res;

	infos = ft_parse_header_values(m_in);
	if (!infos)
	{
		ft_free_2d_char_array(m_in, nbr_line);
		return (0);
	}
	res = ft_struct_initialize(infos, ft_strlen(m_in[1]), m_dat);
	if (!res)
		return (0);
	free(infos);
	while (m_dat->current_line < m_dat->nbr_line)
	{
		if (!ft_validate_row(m_in[m_dat->current_line + 1], m_dat))
		{
			ft_free_2d_char_array(m_in, m_dat->nbr_line + 1);
			ft_struct_free_map(m_dat);
			return (0);
		}
		m_dat->current_line++;
	}
	ft_free_2d_char_array(m_in, m_dat->nbr_line + 1);
	return (1);
}
