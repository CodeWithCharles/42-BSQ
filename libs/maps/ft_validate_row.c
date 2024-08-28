/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:12:58 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 15:19:53 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	ft_validate_row(char *row, t_map *map_datas)
{
	unsigned int	i;

	i = 0;
	if (!row)
	{
		ft_print_error("map error\n");
		return (0);
	}
	while (row[i] != '\n' && row[i])
	{
		if (row[i] != map_datas->empty && row[i] != map_datas->obs)
		{
			ft_print_error("map error\n");
			return (0);
		}
		i++;
	}
	if (i != map_datas->nbr_column)
	{
		ft_print_error("map error\n");
		return (0);
	}
	map_datas->map[map_datas->current_line] = ft_strdup(row, 0, ft_strlen(row));
	return (1);
}
