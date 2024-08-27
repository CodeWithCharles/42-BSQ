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

int	*ft_parse_header_values(char *infos, int len)
{
	int	*result;

	if (!(ft_validate_header(infos)))
		return (NULL);
	result = malloc(4 * sizeof(int));
	if (!result)
		return (NULL);
	result[1] = infos[len - 3] - '0';
	result[2] = infos[len - 2] - '0';
	result[3] = infos[len - 1] - '0';
	infos[len - 3] = '\0';
	result[0] = atoi(infos);
	free(infos);
	return (result);
}
