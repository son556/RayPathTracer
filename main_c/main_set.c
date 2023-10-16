/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:39:31 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 19:36:42 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	texture_img(t_mlx *mlx)
{
	mlx->block_c.data.img = mlx_xpm_file_to_image(mlx->mlx, \
		"./xpm/blockcolor.xpm", &mlx->block_c.width, &mlx->block_c.height);
	mlx->block_c.data.addr = mlx_get_data_addr(mlx->block_c.data.img, \
		&mlx->block_c.data.bits_per_pixel, &mlx->block_c.data.line_length \
		, &mlx->block_c.data.endian);
	mlx->block_b.data.img = mlx_xpm_file_to_image(mlx->mlx, \
		"./xpm/blocknormal.xpm", &mlx->block_b.width, &mlx->block_b.height);
	mlx->block_b.data.addr = mlx_get_data_addr(mlx->block_b.data.img, \
		&mlx->block_b.data.bits_per_pixel, &mlx->block_b.data.line_length \
		, &mlx->block_b.data.endian);
}

void	set_cam(t_main *m, t_vec3 point, t_vec3 n_vec, int fov)
{
	m->res_ratio = 16.0 / 9.0;
	m->point_y = 700;
	m->point_x = m->point_y * m->res_ratio;
	m->theta = getradian(fov);
	m->h = tan(m->theta / 2);
	m->vp_height = 2.0 * m->h;
	m->vp_width = m->res_ratio * m->vp_height;
	m->look_from = point;
	if (n_vec.x == 0 && n_vec.z == 0 && (n_vec.y == 1 || n_vec.y == -1))
		m->vup = vec3init(0, 0, 1);
	else
		m->vup = vec3init(0, 1, 0);
	m->w_vec = n_vec;
	m->u_vec = normalize_vec3(cross_vec3(m->vup, m->w_vec));
	m->v_vec = cross_vec3(m->w_vec, m->u_vec);
	m->horizontal = mul_vec3(m->u_vec, m->vp_width);
	m->vertical = mul_vec3(m->v_vec, m->vp_height);
	m->origin = m->look_from;
	m->ll_corner = sub_vec3(m->origin, mul_vec3(m->horizontal, 0.5));
	m->ll_corner = sub_vec3(m->ll_corner, mul_vec3(m->vertical, 0.5));
	m->ll_corner = sub_vec3(m->ll_corner, m->w_vec);
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, m->point_x, m->point_y, "test");
}

t_obj	set_sphere(t_sph_mat sph)
{
	t_obj	obj_sph;

	complete_sphere(&(obj_sph.sphere), sph.cen, sph.diameter * 0.5);
	obj_sph.type = SPHERE;
	obj_sph.color = sph.col;
	if (7 <= sph.material && sph.material <= 9)
		obj_sph.material = sph.material;
	else
		obj_sph.material = PLASTIC;
	if (11 <= sph.texture && sph.texture <= 13 && obj_sph.material == PLASTIC)
		obj_sph.texture = sph.texture;
	if (obj_sph.material == METAL)
		obj_sph.fuzz = sph.fuzz;
	if (obj_sph.material == GLASS)
		obj_sph.ref_idx = sph.ref_idx;
	return (obj_sph);
}

t_obj	set_plane(t_pl_mat pl)
{
	t_obj	obj_pl;

	obj_pl.type = PLANE;
	obj_pl.color = pl.col;
	obj_pl.material = PLASTIC;
	complete_plane(&(obj_pl.plane), pl.cen, pl.n_vec);
	obj_pl.color = pl.col;
	return (obj_pl);
}

t_obj	set_cyl(t_cyl_mat cyl)
{
	t_obj	obj_cyl;

	obj_cyl.type = CYLINDER;
	obj_cyl.color = cyl.col;
	complete_cyl(&(obj_cyl.cylinder), cen_vec_rh_init(cyl.cen, cyl.n_vec, \
		vec3init(cyl.diameter * 0.5, cyl.height, 0)));
	if (7 <= cyl.material && cyl.material <= 9)
		obj_cyl.material = cyl.material;
	else
		obj_cyl.material = PLASTIC;
	if (11 <= cyl.texture && cyl.texture <= 13 && obj_cyl.material == PLASTIC)
		obj_cyl.texture = cyl.texture;
	if (obj_cyl.material == METAL)
		obj_cyl.fuzz = cyl.fuzz;
	if (obj_cyl.material == GLASS)
		obj_cyl.ref_idx = cyl.ref_idx;
	return (obj_cyl);
}
