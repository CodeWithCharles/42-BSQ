/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_solutions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:06:30 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 20:22:35 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

void	ft_struct_free_solutions(t_map *map_data)
{
	int	i;

	i = -1;
	while (map_data->sols[++i])
		free(map_data->sols[i]);
	free(map_data->sols);
}
