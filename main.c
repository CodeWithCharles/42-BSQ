/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:09:07 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 16:07:47 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib.h"

int	main(int argc, char **argv)
{
	char			*file_content;
	char			**map;
	t_map			*map_data;
	unsigned int	i;

	if (argc != 2)
	{
		write(2, "Usage: ./program <filename>\n", 29);
		return (1);
	}
	file_content = read_file_to_string(argv[1]);
	if (!file_content)
	{
		write(2, "Error reading file\n", 20);
		return (1);
	}
	map = ft_split(file_content, "\n");
	free(file_content);
	map_data = ft_map_to_struct(map);
	free(map);
	i = 0;
	if (map_data != NULL)
	{
		while (i < map_data->nbr_line)
		{
			write(1, map_data->map[i], ft_strlen(map_data->map[i]));
			free(map_data->map[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	free(map_data->map);
	free(map_data);
	return (0);
}
