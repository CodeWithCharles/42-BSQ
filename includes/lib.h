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

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_char_is_space(char c);
int		ft_has_duplicates(char *str);
int		ft_count_string_in_array(char **arr);
int		*ft_parse_header_values(char *infos, int len);
int		*ft_validate_header(char *infos);
t_map	*ft_map_to_struct(char **map_input, t_map *map_data);
int		ft_validate_row(char *row, int length, char empty, char obs);

typedef struct s_map
{
	char			**map;
	int				**solutions;
	char			empty;
	char			filler;
	char			obs;
	unsigned int	nbr_line;
	unsigned int	nbr_column;
}	t_map;

#endif
