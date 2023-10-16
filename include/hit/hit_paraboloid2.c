/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:31:35 by chanson           #+#    #+#             */
/*   Updated: 2023/05/18 14:23:59 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

double	paraboloid_r(t_para	para)
{
	double	r;

	r = sqrt(2 * para.len * para.len_cc);
	return (r);
}

void	complete_para(t_para *para, t_vec3 center, t_vec3 move, double len)
{
	para->cen = center;
	para->pl.center = sub_vec3(para->cen, move);
	para->pl.n_vec = normalize_vec3(move);
	para->len = len;
	para->len_cc = len_vec3(sub_vec3(para->cen, para->pl.center));
	para->r = paraboloid_r(*para);
}

t_aabb	paraboloid_aabb_box(t_para para)
{
	t_aabb	bound_box;
	t_vec3	up;
	t_vec3	down;
	double	a;
	double	b;

	up = add_vec3(para.cen, mul_vec3(para.pl.n_vec, \
		para.len - 0.5 * para.len_cc));
	down = mul_vec3(add_vec3(para.cen, para.pl.center), 0.5);
	a = up.x + up.y + up.z;
	b = down.x + down.y + down.z;
	if (a < b)
	{
		bound_box.maximum = up;
		up = down;
		down = bound_box.maximum;
	}
	bound_box.minimum = sub_vec3(down, vec3init(para.r, para.r, para.r));
	bound_box.maximum = add_vec3(up, vec3init(para.r, para.r, para.r));
	return (bound_box);
}
