/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:09:07 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 01:09:07 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lib.h"

int	main(int argc, char **argv)
{
	char	*file_content;

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
	write(1, file_content, ft_big_strlen(file_content));
	free(file_content);
	return (0);
}
