/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cube_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:02:23 by chanson           #+#    #+#             */
/*   Updated: 2023/05/08 21:43:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	_make_cube_(t_cube *cube, t_vec3 *point)
{
	cube->plane[0].plane_vertex[0] = point[0];
	cube->plane[0].plane_vertex[1] = point[1];
	cube->plane[0].plane_vertex[2] = point[2];
	cube->plane[0].plane_vertex[3] = point[3];
	cube->plane[1].plane_vertex[0] = point[4];
	cube->plane[1].plane_vertex[1] = point[5];
	cube->plane[1].plane_vertex[2] = point[6];
	cube->plane[1].plane_vertex[3] = point[7];
	cube->plane[2].plane_vertex[0] = point[0];
	cube->plane[2].plane_vertex[1] = point[1];
	cube->plane[2].plane_vertex[2] = point[5];
	cube->plane[2].plane_vertex[3] = point[4];
	cube->plane[3].plane_vertex[0] = point[0];
	cube->plane[3].plane_vertex[1] = point[3];
	cube->plane[3].plane_vertex[2] = point[7];
	cube->plane[3].plane_vertex[3] = point[4];
	cube->plane[4].plane_vertex[0] = point[1];
	cube->plane[4].plane_vertex[1] = point[2];
	cube->plane[4].plane_vertex[2] = point[6];
	cube->plane[4].plane_vertex[3] = point[5];
	cube->plane[5].plane_vertex[0] = point[3];
	cube->plane[5].plane_vertex[1] = point[2];
	cube->plane[5].plane_vertex[2] = point[6];
	cube->plane[5].plane_vertex[3] = point[7];
}

static void	make_cube_(t_cube *cube)
{
	t_vec3	point[8];

	point[0] = add_vec3(cube->plane[0].center, \
		mul_vec3(cube->plane[2].n_vec, cube->len / 2));
	point[0] = add_vec3(point[0], \
		mul_vec3(cube->plane[3].n_vec, cube->len / 2));
	point[1] = add_vec3(point[0], mul_vec3(cube->plane[4].n_vec, cube->len));
	point[2] = add_vec3(point[1], mul_vec3(cube->plane[5].n_vec, cube->len));
	point[3] = add_vec3(point[2], mul_vec3(cube->plane[3].n_vec, cube->len));
	point[4] = add_vec3(point[0], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[5] = add_vec3(point[1], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[6] = add_vec3(point[2], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[7] = add_vec3(point[3], mul_vec3(cube->plane[1].n_vec, cube->len));
	cube->t_root = 0;
	_make_cube_(cube, &(point[0]));
}

static void	make_cube(t_cube *cube)
{
	int		i;
	int		j;
	t_vec3	n_vec[6];

	n_vec[0] = cube->n_vec;
	n_vec[1] = normalize_vec3(mul_vec3(n_vec[0], -1));
	n_vec[2] = cube->n_vec_2;
	n_vec[3] = normalize_vec3(cross_vec3(n_vec[0], n_vec[2]));
	n_vec[4] = normalize_vec3(mul_vec3(n_vec[3], -1));
	n_vec[5] = normalize_vec3(mul_vec3(n_vec[2], -1));
	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 6)
		{
			cube->plane[i].n_vec = n_vec[i];
			cube->plane[i].center = add_vec3(cube->cube_c, \
				mul_vec3(n_vec[i], cube->len / 2));
		}
	}
	make_cube_(cube);
}

t_vec3x3	make_n1_n2_c(t_vec3 n1, t_vec3 n2, t_vec3 cen)
{
	t_vec3x3	n1n2c;

	n1n2c.v_x = normalize_vec3(n1);
	n1n2c.v_y = normalize_vec3(n2);
	n1n2c.v_z = cen;
	return (n1n2c);
}

void	complete_cube(t_cube *cube, t_vec3x3 n1_n2_c, double l)
{
	cube->n_vec = n1_n2_c.v_x;
	cube->n_vec_2 = n1_n2_c.v_y;
	cube->cube_c = n1_n2_c.v_z;
	cube->len = l;
	make_cube(cube);
}
