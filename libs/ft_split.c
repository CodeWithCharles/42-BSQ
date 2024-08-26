/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 01:00:22 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 01:00:22 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_is_char_separator(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
		if (sep[i++] == c)
			return (1);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**dest;
	int		start_sub_str;
	int		curr_arr_idx;

	i = 0;
	curr_arr_idx = 0;
	dest = malloc((ft_strlen(str) + 1) * sizeof(char *));
	while (str[i])
	{
		while (str[i] && ft_is_char_separator(charset, str[i]))
			i++;
		start_sub_str = i;
		while (str[i] && !ft_is_char_separator(charset, str[i]))
			i++;
		if (start_sub_str < i)
			dest[curr_arr_idx++] = ft_strdup(str, start_sub_str, i);
	}
	dest[curr_arr_idx] = NULL;
	return (dest);
}
