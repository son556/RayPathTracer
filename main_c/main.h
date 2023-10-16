/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:45:58 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 19:49:59 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../include/vec3.h"
# include "../include/ray.h"
# include "../include/hit.h"
# include "../include/mlx_function.h"
# include "../include/pthread.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_sph_mat
{
	t_vec3			cen;
	double			diameter;
	t_color3		col;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_sph_mat;

typedef struct s_pl_mat
{
	t_vec3		cen;
	t_vec3		n_vec;
	t_color3	col;
}	t_pl_mat;

typedef struct s_cyl_mat
{
	t_vec3			cen;
	t_vec3			n_vec;
	t_color3		col;
	double			diameter;
	double			height;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_cyl_mat;

typedef struct s_con_mat
{
	t_vec3			cen;
	t_vec3			n_vec;
	t_color3		col;
	double			diameter;
	double			height;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_con_mat;

typedef struct s_cub_mat
{
	t_vec3			cen;
	t_vec3			n_vec1;
	t_vec3			n_vec2;
	t_color3		col;
	double			len;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_cub_mat;

typedef struct s_par_mat
{
	t_vec3			cen;
	t_vec3			move;
	t_color3		col;
	double			len;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_par_mat;

typedef struct s_xyz_mat
{
	t_vec3			cen;
	t_color3		col;
	double			len;
	int				xyz_type;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
}	t_xyz_mat;

// main_draw
void	*draw(void *arg);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_strexit(char *str);
void	free_split(char **split);
t_vec3	check_vec(char *str, char *err_m);
double	check_num(char *str, char *err_m);
double	ft_atof(char *str);

// main_set
void	texture_img(t_mlx *mlx);
void	set_cam(t_main *m, t_vec3 point, t_vec3 n_vec, int fov);
t_obj	set_sphere(t_sph_mat sph);
t_obj	set_plane(t_pl_mat pl);
t_obj	set_cyl(t_cyl_mat cyl);

// main_set2
t_obj	set_cone(t_con_mat con);
t_obj	set_cube(t_cub_mat cub);
t_obj	set_para(t_par_mat par);
t_obj	set_light(t_vec3 point, t_color3 col, double rat, int n);
t_obj	set_xyz(t_xyz_mat xyz);

// main_parse
t_obj	*check_scene(int argc, char **argv, t_list_pth *list);

// main_parse2
void	parsing_rt(char *str, t_obj *obj, int idx);

// main_parse3
void	parsing_light(char **str, t_obj *obj, int idx);
void	parsing_sp(char **str, t_obj *obj, int idx);
void	parsing_cy(char **str, t_obj *obj, int idx);
void	parsing_pl(char **str, t_obj *obj, int idx);
void	parsing_cu(char **str, t_obj *obj, int idx);

// main_parse4
void	parsing_co(char **str, t_obj *obj, int idx);
void	parsing_pa(char **str, t_obj *obj, int idx);
void	parsing_xy(char **str, t_obj *obj, int idx);
void	parsing_xz(char **str, t_obj *obj, int idx);
void	parsing_yz(char **str, t_obj *obj, int idx);
#endif