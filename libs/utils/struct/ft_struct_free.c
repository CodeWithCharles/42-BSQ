/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:16:04 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:32:32 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

void	ft_struct_free(t_map *map_data)
{
	if (map_data)
	{
		if (map_data->map != NULL)
			ft_struct_free_map(map_data);
		if (map_data->solutions != NULL)
			ft_struct_free_solutions(map_data);
		free(map_data);
	}
}
