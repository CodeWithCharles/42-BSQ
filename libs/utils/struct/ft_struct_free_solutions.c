/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_solutions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:14:13 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:31:03 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/lib.h"

void	ft_struct_free_solutions(t_map *map_data)
{
	int	i;

	i = -1;
	while (map_data->solutions[++i])
		free(map_data->solutions[i]);
}
