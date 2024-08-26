/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:39:39 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 22:13:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_map	*ft_map_to_struct(char **map_input, t_map *map_data)
{
	int		*infos;
	int		i;

	infos = validate_header(map_input[0]);
	map_data = malloc(sizeof(struct s_map));
	if (infos == NULL || map_data == NULL)
		return (NULL);
	map_data->filler = infos[3] + '0';
	map_data->obs = infos[2] + '0';
	map_data->empty = infos[1] + '0';
	map_data->nbr_line = infos[0];
	map_data->nbr_column = ft_strlen(map_input) - 1;
	free(infos);
	if (map_data->nbr_column < 1)
	{
		ft_print_error("Map error : Map cannot have less than 2 lines.");
		free(map_data);
		return (NULL);
	}
	i = 1;
	while (i < map_data->nbr_column)
		map_data->map[i - 1] = map_input[i];
	return (map_data);
}
