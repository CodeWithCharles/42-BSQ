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

t_map	*ft_struct_initialize_solutions(t_map *map_data)
{
	unsigned int	i;

	map_data->sols = malloc(sizeof(int *) * map_data->nbr_line);
	if (!map_data->sols)
		ft_print_error("Error: allocating memory to solutions\n");
	else
	{
		i = 0;
		while (i < map_data->nbr_column)
		{
			map_data->sols[i] = malloc(sizeof(int) * map_data->nbr_column);
			if (!map_data->sols[i])
			{
				ft_print_error("Error: allocating memory to solutions rows.\n");
				ft_struct_free(map_data);
				return (NULL);
			}
			i++;
		}
	}
	return (map_data);
}
