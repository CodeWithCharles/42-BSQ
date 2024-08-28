/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:06:30 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:29:06 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

void	ft_struct_free_map(t_map *map_data)
{
	unsigned int	i;

	i = 0;
	while (i < map_data->current_line)
		free(map_data->map[i++]);
	free(map_data->map);
}
