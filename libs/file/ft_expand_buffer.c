/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:50:18 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 00:50:18 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

char	*ft_expand_buffer(char *content, size_t *allocated_size)
{
	size_t	new_size;
	char	*new_content;

	new_size = *allocated_size + BUFFER_SIZE;
	new_content = malloc(new_size + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	ft_strcpy(new_content, content);
	free(content);
	*allocated_size = new_size;
	return (new_content);
}
