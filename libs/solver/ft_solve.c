/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:09:45 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 21:09:45 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_solve(t_map *m_dat)
{
	ft_retrieve_areas(m_dat);
	ft_convert_map_chars(m_dat);
	ft_display_solved_map(m_dat);
}
