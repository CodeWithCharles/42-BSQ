/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_to_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:54:53 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 00:54:53 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

char	*ft_read_file_to_string(const char *filename)
{
	int		fd;
	char	*content;
	size_t	total_size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = malloc(BUFFER_SIZE + 1);
	if (!content)
	{
		close(fd);
		return (NULL);
	}
	total_size = 0;
	content[0] = '\0';
	content = ft_read_content(fd, content, &total_size);
	if (!content)
	{
		close(fd);
		return (NULL);
	}
	content[total_size] = '\0';
	close(fd);
	return (content);
}
