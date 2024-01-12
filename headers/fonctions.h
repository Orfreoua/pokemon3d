/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:44:58 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:46:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H

# include "headers.h"

int		print_error(char *msg);
void	free_error(t_data *data, char *msg);
int		load_fole(t_data *data, char *fole);
int		all_data_is_recovered(t_data *data);
void	init_fole(t_fole *fole);
int		parsing_map(t_data *data, char *fole);
int		parsing_map_nxt(t_data *data, int ret, char *line, char **str);
int		it_s_ok_to_be_line(t_data *data, char *line);
int		get_colors(char *line, int x, t_color *color, t_data *data);
int		ft_is_digit(int c);
int		ft_atoii(const char *str, int x);
char	*get_the_line(char *line, int x, t_data *data);
int		is_it_direction(char *line, int x);
int		pars_error(int ret, t_data *data);
int		map_error(t_data *data);
int		shake_colors(t_color *color, t_data *data);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
char	*malicious(char *str);
char	*mali(char c);
char	*joi(char *s1, char *s2);
char	*join_fr(char *s1, char *s2);
int		ft_strlenn(char *str);
char	*print_error_null(char *msg);
int		print_error_to_free(char *msg);
int		petf(char *msg);
char	*cftp(char *str, int s, int e);
char	*cut_spaces(char *str);
int		parsing_mapy(char *str, char *src, t_fole *fole);
int		create_map(char *str, t_data *data);
int		str_c(char *str, char c);
void	init_fole_nxt(t_fole *fole);
int		pars_error_map(int ret, t_data *data);
void	create_tab(t_fole *fole, char *str);
int		**cpy_tab(t_fole *fole, int **tmp);
int		**add_to_tab(int **tab, char *str, int stop, int size);
int		convert(char c);
int		ft_is_cap_alpha(int c);
double	player_pos(char c, t_fole *fole, int x, int y);
void	free_tab(int **tab, int size);
void	free_tab_bis(int **tab, int y);
void	free_all(t_data *data);
void	free_strings(t_fole *fole);
void	free_alll(t_fole *fole);
int		space(char *str);
int		check_map(t_data *data);
void	cpy_map_tab(t_fole *fole);
int		len_x(int **map, int y);
int		len_y(int **map);
void	parse_tab(t_fole *fole);
int		is_one_space(char *line, int x);
char	*cftp(char *str, int s, int e);
int		get_rgb_r(char *line, int x, t_color *color);
int		get_rgb_g(char *line, int x, t_color *color);
int		get_rgb_b(char *line, int x, t_color *color);
int		convert(char c);
double	player_pos(char c, t_fole *fole, int x, int y);
int		**malloc_one_tab(t_fole *fole);
void	check_wall(t_fole *fole);
void	check_space_nxt(t_fole *fole, int y, int x);
void	check_space_nxt_bis(t_fole *fole, int y, int x);
void	check_space(t_fole *fole);
void	is_one(t_fole *fole, int y, int x);
void	is_one_nxt(t_fole *fole, int y, int x);
void	is_one_nxt_nxt(t_fole *fole, int y, int x);
void	is_one_nxt_nxt_end(t_fole *fole, int y, int x);
void	put_err_msg(t_fole *fole, char *msg);
int		**err_in_add(t_fole *fole, int y, char *msg);
void	check_missing_pos(t_data *data);
void	transformers(t_fole *fole, int zone, int new);
void	err_in_bis(t_fole *fole, int y, char *msg);
int		ft_check(char *str);
char	*ft_read_suite(int fd, int n, char *strr, int *rid);
int		ft_read(char **str, int fd);
int		get_next_lineo(int fd, char **line, char **str);
char	*ft_nextline(char **str);
int		free_for_rtn(void *ptr, int rtn);
char	*lolilol(char **str, char *strr, int x, int y);
int		s_y_tab(int **tab, int stop);
int		s_x_tab(int **tab, int stop, int y);
char	**last_for_screen(t_data *data, int y);
void	print_map(char **tab);
void	check_wall_bis(t_fole *fole);
void	cpy_tab_tab_bis(t_fole *fole);
int		big_len_y(int **map);
void	map_moins_un(t_fole *fole, int y, int x);
void	cpy_next(t_fole *fole, int y, char *msg);
void	is_two(t_fole *fole, int y, int x);
void	transformers_bis(t_fole *fole);
void	check_wall_bis(t_fole *fole);
void	check_space_nxt_b(t_fole *fole, int y, int x, int **tab);
void	check_space_nxt_bis_b(t_fole *fole, int y, int x, int **tab);
void	check_taby(t_fole *fole, int x, int y);
void	taby_y_x(t_fole *fole, int x, int y);
void	taby_y(t_fole *fole, int x, int y);
void	taby_x(t_fole *fole, int x, int y);
void	taby_else(t_fole *fole, int x, int y);
void	extra_long_if(t_fole *fole, int x, int y);
void	for_is_two(t_fole *fole);
void	find_stack(t_fole *fole);
int		verif(int **tab, int y, int x, t_fole *fole);
void	new_small_stack(t_fole *fole);
void	map_moins_un_b(t_fole *fole, int y, int x);
void	free_tabs(t_data *data);
void	free_mapy(t_data *data);
void	free_all_nxt(t_data *data);
void	all_in_struct(t_data *data);
void	cpy_tab_tab_bis(t_fole *fole);
void	print_fole(t_data *data);
void	print_tab(int **tab, int stop);
void	draw_full_circle(t_data *data, int x, int y, int radius);
void	draw_background(t_data *data);
int		key_hook(int key, t_data *data);
int		end(t_data *data);
int		get_fole_position(t_data *data, double x, double y);
int		failed(t_data *data, char *msg);
int		pos_x_max_int(t_data *data);
int		create_trgb(t_color rgb);
char	**free_tab_to_x(char **tab, int x);
char	*free_str(char *str);
void	exit_mlx(t_data *data, char *msg_error, int step);
char    **bonus_map(char **first, t_fole *fole);



void	init_variable(t_data *data);
int		release_key(int key_code, t_data *data);
int		press_key(int key_code, t_data *data);
int		raycasting(t_data *data);
void	draw_wall(t_data *data, int x, double distance, t_img texture);
double	calculate_distance_x(t_data *data);
double	calculate_distance_y(t_data *data);
double	degrees_to_radians(double deg);
void	increment_ray(t_ray *ray);
void	init_ray(t_data *data);
void	move(t_data *data);
int		is_walkable(const t_data *data, double x, double y);
int		ft_strlen(char *s);
int		close_window(t_data *data);
void	draw_background(t_data *data);
int		hit_wall(t_data *data, int i, int map_width);
t_img	choose_texture(t_data *data, int i);
int     load_texture(t_data *data, t_img *texture, char *path);
void    load_wall(t_data *data);
void	load_textures(t_data *data);
void    load_tree(t_data *data);
void    load_house(t_data *data);
void    load_labo_r(t_data *data);
void    load_labo_l(t_data *data);
void    load_river(t_data *data);
void    setting(t_data *data);
void	shiffting(t_data *data, double cos, double sin, double speed);
int     load_drago(t_data *data, t_drago *drago);
int     load_drago_b(t_data *data, t_drago *drago);
#endif
