/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:12:58 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 22:12:58 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_validate_row(char *row, int length, char empty, char obs)
{
	int	i;

	i = 0;
	while (row[i] != '\n' && row[i])
	{
		if (i >= length || (row[i] != empty && row[i] != obs))
			return (0);
		i++;
	}
	return (1);
}
