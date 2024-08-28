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

char	*ft_read_content(int fd, char *content, size_t *r_size, size_t *c_size)
{
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, content + *r_size, *c_size - *r_size);
		if (bytes_read < 0)
		{
			free(content);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		*r_size += (size_t)bytes_read;
		if (*r_size >= *c_size)
		{
			content = ft_expand_buffer(content, c_size);
			if (!content)
				return (NULL);
		}
	}
	return (content);
}
