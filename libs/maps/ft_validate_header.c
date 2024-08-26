/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:53:18 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 22:13:04 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*ft_validate_header(char *infos)
{
	int	len;
	int	i;

	len = ft_strlen(infos);
	if (len < 4)
		return (NULL);
	i = -1;
	while (++i < len)
		if (!(infos[i] >= ' ' && infos[i] <= '~')
			|| (i < len - 3 && !isdigit(infos[i])))
			return (NULL);
	if (infos[len - 3] == infos[len - 2]
		|| infos[len - 3] == infos[len - 1] || infos[len - 2] == infos[len - 1])
		return (NULL);
	return (ft_parse_header_values(infos, len));
}
