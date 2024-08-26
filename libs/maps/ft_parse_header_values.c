/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:32:40 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 22:32:40 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	*ft_parse_header_values(char *infos, int len)
{
	int	*result;

	result = malloc(4 * sizeof(int));
	if (!result)
		return (NULL);
	result[1] = (int)infos[len - 3];
	result[2] = (int)infos[len - 2];
	result[3] = (int)infos[len - 1];
	infos[len - 3] = '\0';
	result[0] = atoi(infos);
}
