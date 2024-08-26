/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:39:39 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 19:07:08 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_map	*validate_map(char **map_input)
{
	int		infos_len;
	t_map	*map_data;

	infos_len = validate_infos(map_input[0]);
	map_data = malloc(sizeof(struct s_map));
	if (infos_len == 0 || map_data == NULL)
	{
		(*map_data).map = NULL;
		return (map_data);
	}
	(*map_data).filler = map_input[0][infos_len - 1];
	(*map_data).obs = map_input[0][infos_len - 2];
	(*map_data).empty = map_input[0][infos_len - 3];
}

// Returns length of infos row if valid, else returns 0
int	validate_infos(char *infos)
{
	int		infos_len;
	int		i;
	int		k;

	infos_len = ft_strlen(infos);
	if (infos_len < 5)
		return (0);
	while (i < infos_len && infos[i] && infos[i] != '\n')
	{
		if ((i >= 3 && !(infos[i] >= '0' && infos[i] <= '9'))
			|| (infos[i] <= ' ' && infos[i] >= '~'))
			return (0);
		i++;
	}
	if (infos[infos_len - 1] == infos[infos_len - 2]
		|| infos[infos_len - 1] == infos [infos_len - 3]
		|| infos[infos_len - 2] == infos[infos_len - 3])
		return (0);
	return (infos_len);
}

// Returns 1 if valid, 0 if not
int	validate_row(char *row, int length, char empty, char obs)
{
	int	i;

	i = 0;
	while (row[i] != '\n' && row[i])
	{
		if (i >= length || (row[i] != empty && row[i] != obs))
			return (0);
		i++;
	}
	return (1);
}
