/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:58:59 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 15:46:35 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

char	*ft_strdup(char *src, int from_idx, int to_idx)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((to_idx - from_idx + 1) * sizeof(char));
	while (i < to_idx - from_idx)
	{
		dest[i] = src[i + from_idx];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
