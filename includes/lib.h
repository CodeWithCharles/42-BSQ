/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:23:19 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/26 18:46:44 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

#include <stdlib.h>

int	ft_strlen(char *str);

int	validate_infos(char *infos);
int	validate_map(char **map);

typedef struct s_map
{
	char				**map;
	int					**solutions;
	char				empty;
	char				filler;
	char				obs;
	unsigned int		nbr_line;
	unsigned int		nbr_column;
}	t_map;

#endif
