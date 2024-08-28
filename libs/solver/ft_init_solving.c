/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:21:56 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 18:21:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_init_solving(char *file, t_map *map_data)
{
	char	*file_content;
	int		res;
	char	**map;
	int		nbr_line;

	res = 0;
	file_content = ft_read_file_to_string(file);
	if (file_content)
	{
		map = malloc((ft_strlen(file_content) + 1) * sizeof(char *));
		nbr_line = ft_split(map, file_content, "\n");
		res = ft_map_to_struct(map, map_data, nbr_line);
		free(file_content);
		if (res)
		{
			res = ft_struct_initialize_solutions(map_data);
			if (res)
				ft_solve(map_data);
		}
	}
	if (res)
		ft_struct_free(map_data);
}
