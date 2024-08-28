/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_to_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:28:49 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/28 03:28:49 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	ft_open_file_if_needed(char *filename, int *f_opened)
{
	int	fd;

	fd = 0;
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (-1);
		*f_opened = 1;
	}
	return (fd);
}

char	*ft_handle_allocation_failure(int f_opened, int fd)
{
	if (f_opened)
		close(fd);
	return (NULL);
}

char	*ft_finalize_read(char *content, size_t t_size, int f_opened, int fd)
{
	if (f_opened)
		close(fd);
	if (content)
		content[t_size] = '\0';
	return (content);
}

char	*ft_read_file_to_string(char *filename)
{
	int		fd;
	char	*content;
	size_t	t_size;
	size_t	allocated_size;
	int		f_opened;

	f_opened = 0;
	fd = ft_open_file_if_needed(filename, &f_opened);
	if (fd < 0)
		return (NULL);
	content = malloc(BUFFER_SIZE + 1);
	if (!content)
		return (ft_handle_allocation_failure(f_opened, fd));
	t_size = 0;
	allocated_size = BUFFER_SIZE;
	content[0] = '\0';
	content = ft_read_content(fd, content, &t_size, &allocated_size);
	return (ft_finalize_read(content, t_size, f_opened, fd));
}
