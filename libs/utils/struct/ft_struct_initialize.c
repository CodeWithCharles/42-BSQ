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

int	ft_struct_initialize(int *infos, int col_len, t_map *map_data)
{
	if (!infos)
		return (0);
	map_data->filler = infos[3] + '0';
	map_data->obs = infos[2] + '0';
	map_data->empty = infos[1] + '0';
	map_data->nbr_line = infos[0];
	map_data->current_line = 0;
	map_data->nbr_column = col_len;
	map_data->sol_max_area = 0;
	map_data->map = malloc(sizeof(char *) * (map_data->nbr_line + 1));
	if (map_data->map == NULL)
	{
		ft_print_error("Error : allocating map memory failed.\n");
		return (0);
	}
	return (1);
}
