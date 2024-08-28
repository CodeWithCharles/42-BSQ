/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:21:26 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:33:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	ft_free_2d_char_array(char **arr, int nbr_row)
{
	int	i;

	i = 0;
	while (i < nbr_row)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_2d_int_array(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
