/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_solving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:21:56 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 18:21:56 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	init_solving(char *file)
{
	t_map	*map_data;
	char	*file_content;

	file_content = ft_read_file_to_string(file);
	if (!file_content)
		ft_print_error("Error: error while reading file.");
	else
	{
		
	}
}
