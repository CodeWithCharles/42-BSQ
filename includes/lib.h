/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:23:19 by cpoulain          #+#    #+#             */
/*   Updated: 2024/08/27 17:26:14 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	8192
# endif

typedef struct s_map
{
	char			**map;
	unsigned short	**sols;
	char			empty;
	char			filler;
	char			obs;
	unsigned int	nbr_line;
	unsigned int	nbr_column;
	unsigned int	current_line;
	unsigned int	sol_max_area;
	unsigned int	sol_y;
	unsigned int	sol_x;
}	t_map;

// Struct functions
int				ft_struct_initialize(int *infos, int col_len, t_map *map_data);
void			ft_struct_free(t_map *map_data);
void			ft_struct_free_map(t_map *map_data);
void			ft_struct_free_solutions(t_map *map_data);
int				ft_struct_initialize_solutions(t_map *map_data);

// Utils functions
void			ft_print_error(char *str);
void			ft_free_2d_char_array(char **arr, int nbr_rows);
void			ft_free_2d_int_array(int **arr);

// Regular functions
int				ft_atoi(char *str);
int				ft_strlen(char *str);
size_t			ft_big_strlen(char *str);
int				ft_char_is_space(char c);
int				ft_has_duplicates(char *str);
int				ft_count_string_in_array(char **arr);
char			*ft_strdup(char *src, int from_idx, int to_idx);
int				ft_split(char **dest, char *str, char *charset);
char			*ft_strcpy(char *dest, char *src);
unsigned int	ft_min_uint(unsigned int a, unsigned int b);

// Map functions
int				*ft_parse_header_values(char **map);
int				ft_validate_header(char *infos);
int				ft_map_to_struct(char **m_in, t_map *m_dat, int nbr_line);
int				ft_validate_row(char *row, t_map *map_data);
// File functions
char			*ft_expand_buffer(char *content, size_t *c_size);
char			*ft_read_content(int fd, char *content, size_t *r_size,
					size_t *c_size);
char			*ft_read_file_to_string(char *filename);
//Solver functions
void			ft_init_solving(char *file, t_map *map_data);
void			ft_retrieve_areas(t_map *map_data);
void			ft_display_sols_matrix(t_map *m_dat);
void			ft_solve(t_map *m_dat);
void			ft_convert_map_chars(t_map *m_dat);
void			ft_display_solved_map(t_map *m_dat);

#endif
