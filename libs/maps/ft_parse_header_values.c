/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:32:40 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 16:07:41 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	*ft_parse_header_values(char **map)
{
	int	*result;

	if (!map[0] || !map[1])
	{
		ft_print_error("map error\n");
		return (NULL);
	}
	if (!(ft_validate_header(map[0])))
		return (NULL);
	result = malloc(4 * sizeof(int));
	if (!result)
		return (NULL);
	result[1] = map[0][ft_strlen(map[0]) - 3] - '0';
	result[2] = map[0][ft_strlen(map[0]) - 2] - '0';
	result[3] = map[0][ft_strlen(map[0]) - 1] - '0';
	map[0][ft_strlen(map[0]) - 3] = '\0';
	result[0] = atoi(map[0]);
	if (result[0] < 1)
	{
		free(result);
		ft_print_error("map error\n");
		return (NULL);
	}
	return (result);
}
