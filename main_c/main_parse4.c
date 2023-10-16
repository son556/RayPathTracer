/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:30:02 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 18:38:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	parsing_co(char **str, t_obj *obj, int idx)
{
	t_con_mat	con;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 10)
		ft_strexit("error rt file: cone argv cnt\n");
	con.cen = check_vec(str[1], "error rt file: cone center\n");
	con.n_vec = normalize_vec3(check_vec(str[2], \
		"error rt file: cone noraml vec\n"));
	con.col = div_vec3(check_vec(str[3], \
		"error rt file: cone color\n"), 255);
	con.diameter = check_num(str[4], "error rt file: cone diameter\n");
	con.height = check_num(str[5], "error rt file: cone height\n");
	con.material = (int)check_num(str[6], "error rt file: cone material\n");
	con.texture = (int)check_num(str[7], "error rt fiel: cone texture\n");
	con.fuzz = check_num(str[8], "error rt file: cone fuzz\n");
	con.ref_idx = check_num(str[9], "error rt file: cone ref_idx\n");
	obj[idx] = set_cone(con);
}

void	parsing_pa(char **str, t_obj *obj, int idx)
{
	t_par_mat	para;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 9)
		ft_strexit("error rt file: paraboloid argv cnt\n");
	para.cen = check_vec(str[1], "error rt file: paraboloid center\n");
	para.move = check_vec(str[2], "error rt file: paraboloid move\n");
	para.col = div_vec3(check_vec(str[3], \
		"error rt file: paraboloid color\n"), 255);
	para.len = check_num(str[4], "error rt file: paraboloid length\n");
	para.material = (int)check_num(str[5], \
		"error rt file: paraboloid material\n");
	para.texture = (int)check_num(str[6], "error rt file: paraboloid texture\n");
	para.fuzz = check_num(str[7], "error rt file: paraboloid fuzz\n");
	para.ref_idx = check_num(str[8], "error rt file: paraboloid ref_idx\n");
	obj[idx] = set_para(para);
}

void	parsing_xy(char **str, t_obj *obj, int idx)
{
	t_xyz_mat	xy;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 9)
		ft_strexit("error rt file: xy_plane argv cnt\n");
	xy.cen = check_vec(str[1], "error rt file: xy_plane center\n");
	xy.col = div_vec3(check_vec(str[2], \
		"error rt file: xy_plane color\n"), 255);
	xy.len = check_num(str[3], "error rt file: xy_plane length\n");
	xy.xyz_type = (int)check_num(str[4], "error rt file: xy_plane xyz_type\n");
	xy.material = (int)check_num(str[5], "error rt file: xy_plane material\n");
	xy.texture = (int)check_num(str[6], "error rt file: xy_plane texture\n");
	xy.fuzz = check_num(str[7], "error rt file: xy_plane fuzz\n");
	xy.ref_idx = check_num(str[8], "error rt file: xy_plane ref_idx\n");
	obj[idx] = set_xyz(xy);
}

void	parsing_xz(char **str, t_obj *obj, int idx)
{
	t_xyz_mat	xz;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 9)
		ft_strexit("error rt file: xz_plane argv cnt\n");
	xz.cen = check_vec(str[1], "error rt file: xz_plane center\n");
	xz.col = div_vec3(check_vec(str[2], \
		"error rt file: xz_plane color\n"), 255);
	xz.len = check_num(str[3], "error rt file: xz_plane length\n");
	xz.xyz_type = (int)check_num(str[4], "error rt file: xz_plane xyz_type\n");
	xz.material = (int)check_num(str[5], "error rt file: xz_plane material\n");
	xz.texture = (int)check_num(str[6], "error rt file: xz_plane texture\n");
	xz.fuzz = check_num(str[7], "error rt file: xz_plane fuzz\n");
	xz.ref_idx = check_num(str[8], "error rt file: xz_plane ref_idx\n");
	obj[idx] = set_xyz(xz);
}

void	parsing_yz(char **str, t_obj *obj, int idx)
{
	t_xyz_mat	yz;
	int			cnt;

	cnt = -1;
	while (1)
		if (str[++cnt] == NULL)
			break ;
	if (cnt != 9)
		ft_strexit("error rt file: yz_plane argv cnt\n");
	yz.cen = check_vec(str[1], "error rt file: yz_plane center\n");
	yz.col = div_vec3(check_vec(str[2], \
		"error rt file: yz_plane color\n"), 255);
	yz.len = check_num(str[3], "error rt file: yz_plane length\n");
	yz.xyz_type = (int)check_num(str[4], "error rt file: yz_plane xyz_type\n");
	yz.material = (int)check_num(str[5], "error rt file: yz_plane material\n");
	yz.texture = (int)check_num(str[6], "error rt file: yz_plane texture\n");
	yz.fuzz = check_num(str[7], "error rt file: yz_plane fuzz\n");
	yz.ref_idx = check_num(str[8], "error rt file: yz_plane ref_idx\n");
	obj[idx] = set_xyz(yz);
}
