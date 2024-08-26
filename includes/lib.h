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
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	8192
# endif

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

// Regular functions
int		ft_atoi(char *str);
int		ft_strlen(char *str);
size_t	ft_big_strlen(char *str);
int		ft_char_is_space(char c);
int		ft_has_duplicates(char *str);
int		ft_count_string_in_array(char **arr);
char	*ft_strdup(char *src, int from_idx, int to_idx);
char	**ft_split(char *str, char *charset);
char	*ft_strcpy(char *dest, char *src);
// Map functions
int		*ft_parse_header_values(char *infos, int len);
int		ft_validate_header(char *infos);
t_map	*ft_map_to_struct(char **map_input, t_map *map_data);
int		ft_validate_row(char *row, int length, char empty, char obs);
// File functions
char	*expand_buffer(char *content, size_t *total_size);
char	*read_content(int fd, char *content, size_t *total_size);
char	*read_file_to_string(const char *filename);

#endif
