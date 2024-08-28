/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:53:18 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 14:44:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	ft_validate_header(char *inf)
{
	int	s;
	int	i;

	s = ft_strlen(inf);
	if (!(s < 4))
	{
		i = -1;
		while (++i < s)
		{
			if (!(inf[i] >= ' ' && inf[i] <= '~')
				|| (i < s - 3 && !(inf[i] >= '0' && inf[i] <= '9')))
			{
				ft_print_error("map error\n");
				return (0);
			}
		}
		if (!(inf[s - 3] == inf[s - 2]
				|| inf[s - 3] == inf[s - 1] || inf[s - 2] == inf[s - 1]))
			return (1);
	}
	ft_print_error("map error\n");
	return (0);
}
