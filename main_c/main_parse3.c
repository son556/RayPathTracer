/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:54:18 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 16:06:56 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	parsing_light(char **str, t_obj *obj, int idx)
{
	int			cnt;
	t_vec3		point;
	t_color3	col;
	double		rat;
	int			n;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 5)
		ft_strexit("error rt file: light argv cnt\n");
	point = check_vec(str[1], "error rt file: light point\n");
	rat = check_num(str[2], "error rt file: light ratio\n");
	col = div_vec3(check_vec(str[3], "error rt file: light col\n"), 255.0);
	n = (int)check_num(str[4], "error rt file: light xyz type\n");
	obj[idx] = set_light(point, col, rat, n);
}

void	parsing_sp(char **str, t_obj *obj, int idx)
{
	t_sph_mat	mat;
	int			cnt;

	cnt = -1;
	while (1)
	{
		if (str[++cnt] == NULL)
			break ;
	}
	if (cnt != 8)
		ft_strexit("error rt file: sphere argv cnt\n");
	mat.cen = check_vec(str[1], "error rt file: sphere cneter\n");
	mat.diameter = check_num(str[2], "error rt file: sphere diameter\n");
	mat.col = div_vec3(check_vec(str[3], "error rt file: sphere col\n"), 255);
	mat.material = (int)check_num(str[4], "error rt file: sphere material\n");
	mat.texture = (int)check_num(str[5], "error rt fiel: sphere texture\n");
	mat.fuzz = check_num(str[6], "error rt file: sphere fuzz\n");
	mat.ref_idx = check_num(str[7], "error rt file: sphere ref_idx\n");
	obj[idx] = set_sphere(mat);
}

void	parsing_cy(char **str, t_obj *obj, int idx)
{
	t_cyl_mat	cyl;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 10)
		ft_strexit("error rt file: cylinder argv cnt\n");
	cyl.cen = check_vec(str[1], "error rt file: cylinder center\n");
	cyl.n_vec = normalize_vec3(check_vec(str[2], \
		"error rt file: cylinder noraml vec\n"));
	cyl.col = div_vec3(check_vec(str[3], \
		"error rt file: cylinder color\n"), 255);
	cyl.diameter = check_num(str[4], "error rt file: cylinder diameter\n");
	cyl.height = check_num(str[5], "error rt file: cylinder height\n");
	cyl.material = (int)check_num(str[6], "error rt file: cylinder material\n");
	cyl.texture = (int)check_num(str[7], "error rt fiel: cylinder texture\n");
	cyl.fuzz = check_num(str[8], "error rt file: cylinder fuzz\n");
	cyl.ref_idx = check_num(str[9], "error rt file: cylinder ref_idx\n");
	obj[idx] = set_cyl(cyl);
}

void	parsing_pl(char **str, t_obj *obj, int idx)
{
	t_pl_mat	pl;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 10)
		ft_strexit("error rt file: plane\n");
	pl.cen = check_vec(str[1], "error rt file: plane center\n");
	pl.n_vec = normalize_vec3(check_vec(str[2], \
		"error rt file: plane normal vector\n"));
	pl.col = div_vec3(check_vec(str[3], "error rt file: plane color\n"), 255);
	obj[idx] = set_plane(pl);
}

void	parsing_cu(char **str, t_obj *obj, int idx)
{
	t_cub_mat	cub;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 10)
		ft_strexit("error rt file: cube argv cnt\n");
	cub.cen = check_vec(str[1], "error rt file: cube center\n");
	cub.n_vec1 = normalize_vec3(check_vec(str[2], \
		"error rt file: cube normal vector1\n"));
	cub.n_vec2 = normalize_vec3(check_vec(str[3], \
		"error rt file: cube normal vector2\n"));
	if (dot_vec3(cub.n_vec1, cub.n_vec2) != 0)
		ft_strexit("error rt file: cube vector error\n");
	cub.col = div_vec3(check_vec(str[4], \
		"error rt file: cube color\n"), 255);
	cub.len = check_num(str[5], "error rt file: cube length\n");
	cub.material = (int)check_num(str[6], "error rt file: cube material\n");
	cub.texture = (int)check_num(str[7], "error rt file: cube texture\n");
	cub.fuzz = check_num(str[8], "error rt file: cube fuzz\n");
	cub.ref_idx = check_num(str[9], "error rt file: cube ref_idx\n");
	obj[idx] = set_cube(cub);
}
