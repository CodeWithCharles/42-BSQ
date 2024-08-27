/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:51:21 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 15:33:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

char	*ft_read_content(int fd, char *content, size_t *total_size)
{
	ssize_t	bytes_read;
	size_t	current_buffer_size;

	current_buffer_size = BUFFER_SIZE;
	while (1)
	{
		bytes_read = read(fd, content + *total_size, current_buffer_size);
		if (bytes_read < 0)
		{
			free(content);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		*total_size += (size_t)bytes_read;
		if (*total_size >= current_buffer_size)
		{
			content = ft_expand_buffer(content, total_size);
			if (!content)
				return (NULL);
			current_buffer_size += BUFFER_SIZE;
		}
	}
	return (content);
}
