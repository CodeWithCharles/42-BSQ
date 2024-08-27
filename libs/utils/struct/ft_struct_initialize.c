/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:17:08 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 19:17:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

t_map	*ft_struct_initialize(int *infos)
{
	t_map	*map_data;

	if (!infos)
		return (NULL);
	map_data = malloc(sizeof(t_map));
	if (!map_data)
		ft_print_error("Error: allocating memory to map_data.\n");
	else
	{
		map_data->filler = infos[3] + '0';
		map_data->obs = infos[2] + '0';
		map_data->empty = infos[1] + '0';
		map_data->nbr_line = infos[0];
		map_data->current_line = 0;
	}
	return (map_data);
}
