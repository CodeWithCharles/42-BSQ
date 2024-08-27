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

t_map	*ft_map_to_struct(char **map_input)
{
	int		*infos;
	t_map	*map_data;

	infos = ft_parse_header_values(map_input[0], ft_strlen(map_input[0]));
	map_data = malloc(sizeof(struct s_map));
	if (infos == NULL || map_data == NULL)
		return (NULL);
	map_data->filler = infos[3] + '0';
	map_data->obs = infos[2] + '0';
	map_data->empty = infos[1] + '0';
	map_data->nbr_line = infos[0];
	map_data->nbr_column = ft_strlen(map_input[1]);
	free(infos);
	map_data->current_line = 0;
	map_data->map = malloc(sizeof(char *) * map_data->nbr_line);
	while (map_data->current_line < map_data->nbr_line)
	{
		if (!ft_validate_row(map_input[map_data->current_line + 1], map_data))
		{
			ft_struct_free(map_data);
			return (NULL);
		}
		map_data->current_line++;
	}
	return (map_data);
}
