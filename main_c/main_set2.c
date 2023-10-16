/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:59:34 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 20:29:28 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

t_obj	set_light(t_vec3 point, t_color3 col, double rat, int n)
{
	t_obj	obj_light;

	obj_light.material = LIGHT;
	obj_light.light.color = col;
	obj_light.light.point = point;
	obj_light.light.ratio = rat;
	if (n == 0 || n == 1 || n == 2)
	{
		obj_light.type = XYZ_PLANE;
		obj_light.xyz_pl.cen = point;
	}
	if (n == 0)
		complete_xyz_pl(&(obj_light.xyz_pl), point, 1, 0);
	else if (n == 1)
		complete_xyz_pl(&(obj_light.xyz_pl), point, 1, 1);
	else if (n == 2)
		complete_xyz_pl(&(obj_light.xyz_pl), point, 1, 2);
	else
	{
		obj_light.type = SPHERE;
		complete_sphere(&(obj_light.sphere), point, 1);
	}
	return (obj_light);
}

t_obj	set_cone(t_con_mat con)
{
	t_obj	obj_cone;

	obj_cone.type = CONE;
	obj_cone.color = con.col;
	complete_cone(&(obj_cone.cone), con.cen, con.n_vec, \
		vec3init(con.diameter * 0.5, con.height, 0));
	if (7 <= con.material && con.material <= 9)
		obj_cone.material = con.material;
	else
		obj_cone.material = PLASTIC;
	if (12 <= con.texture && con.texture <= 13 && obj_cone.material == PLASTIC)
		obj_cone.texture = con.texture;
	if (obj_cone.material == METAL)
		obj_cone.fuzz = con.fuzz;
	if (obj_cone.material == GLASS)
		obj_cone.ref_idx = con.ref_idx;
	return (obj_cone);
}

t_obj	set_cube(t_cub_mat cub)
{
	t_obj	obj_cube;

	obj_cube.type = CUBE;
	obj_cube.color = cub.col;
	complete_cube(&(obj_cube.cube), \
		vec3x3init(cub.n_vec1, cub.n_vec2, cub.cen), cub.len);
	if (7 <= cub.material && cub.material <= 9)
		obj_cube.material = cub.material;
	else
		obj_cube.material = PLASTIC;
	if (11 <= cub.texture && cub.texture <= 13 && obj_cube.material == PLASTIC)
		obj_cube.texture = cub.texture;
	if (obj_cube.material == METAL)
		obj_cube.fuzz = cub.fuzz;
	if (obj_cube.material == GLASS)
		obj_cube.ref_idx = cub.ref_idx;
	return (obj_cube);
}

t_obj	set_para(t_par_mat par)
{
	t_obj	obj_para;

	obj_para.type = PARABOLOID;
	obj_para.color = par.col;
	complete_para(&(obj_para.para), par.cen, par.move, par.len);
	if (7 <= par.material && par.material <= 9)
		obj_para.material = par.material;
	else
		obj_para.material = PLASTIC;
	if (11 <= par.texture && par.texture <= 13 && obj_para.material == PLASTIC)
		obj_para.texture = par.texture;
	if (obj_para.material == METAL)
		obj_para.fuzz = par.fuzz;
	if (obj_para.material == GLASS)
		obj_para.ref_idx = par.ref_idx;
	return (obj_para);
}

t_obj	set_xyz(t_xyz_mat xyz)
{
	t_obj	obj_xyz;

	obj_xyz.type = XYZ_PLANE;
	obj_xyz.color = xyz.col;
	complete_xyz_pl(&(obj_xyz.xyz_pl), xyz.cen, xyz.len, xyz.xyz_type);
	obj_xyz.xyz_pl.cen = xyz.cen;
	if (7 <= xyz.material && xyz.material <= 9)
		obj_xyz.material = xyz.material;
	else
		obj_xyz.material = PLASTIC;
	if (11 <= xyz.texture && xyz.texture <= 13 && obj_xyz.material == PLASTIC)
		obj_xyz.texture = xyz.texture;
	if (obj_xyz.material == METAL)
		obj_xyz.fuzz = xyz.fuzz;
	if (obj_xyz.material == GLASS)
		obj_xyz.ref_idx = xyz.ref_idx;
	return (obj_xyz);
}
