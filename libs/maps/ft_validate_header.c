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

int	ft_validate_header(char *infos)
{
	int	len;
	int	i;

	len = ft_strlen(infos);
	if (len < 4)
		return (0);
	i = -1;
	while (++i < len)
	{
		if (!(infos[i] >= ' ' && infos[i] <= '~')
			|| (i < len - 3 && !(infos[i] >= '0' && infos[i] <= '9')))
		{
			ft_print_error("Map error : Invalid header datas.\n");
			return (0);
		}
	}
	if (infos[len - 3] == infos[len - 2]
		|| infos[len - 3] == infos[len - 1] || infos[len - 2] == infos[len - 1])
	{
		ft_print_error("Map error : Char duplication in header row.\n");
		return (0);
	}
	return (1);
}
