/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:07:42 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 20:07:42 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

unsigned int	ft_min_uint(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}
