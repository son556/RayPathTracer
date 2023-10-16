/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:09:00 by chanson           #+#    #+#             */
/*   Updated: 2023/05/31 17:01:27 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	complete_cone(t_cone *con, t_vec3 cen, t_vec3 n_vec, t_vec3 rh)
{
	con->pl.n_vec = normalize_vec3(n_vec);
	con->pl.center = cen;
	con->radius = rh.x;
	con->height = rh.y;
	con->n_vec = mul_vec3(con->pl.n_vec, -1);
	con->c_h = add_vec3(con->pl.center, mul_vec3(con->pl.n_vec, con->height));
	con->c_cos = con->height / sqrt(ft_pow(con->height) + ft_pow(con->radius));
}

void	display_cone(t_cone con)
{
	display_vec3(con.pl.n_vec);
	display_vec3(con.pl.center);
	printf("r: %f h: %f\n", con.radius, con.height);
	display_vec3(con.n_vec);
	display_vec3(con.c_h);
	printf("cos: %f\n\n", con.c_cos);
}

t_aabb	cone_aabb_box(t_cone cone)
{
	t_aabb	bound_box;
	t_vec3	up;
	t_vec3	down;
	double	a;
	double	b;

	a = cone.pl.center.x + cone.pl.center.y + cone.pl.center.z;
	b = cone.c_h.x + cone.c_h.y + cone.c_h.z;
	if (a < b)
	{
		down = cone.pl.center;
		up = cone.c_h;
	}
	else
	{
		down = cone.c_h;
		up = cone.pl.center;
	}
	bound_box.minimum = sub_vec3(down, \
		vec3init(cone.radius, cone.radius, cone.radius));
	bound_box.maximum = add_vec3(up, \
		vec3init(cone.radius, cone.radius, cone.radius));
	return (bound_box);
}

void	get_uv(t_norm *norm, t_vec3 point, t_vec3 cen)
{
	double	theta;
	double	phi;
	t_vec3	tmp_v;

	tmp_v = normalize_vec3(sub_vec3(point, cen));
	theta = acos(-tmp_v.y);
	phi = atan2(tmp_v.z, -tmp_v.x) + PI;
	norm->u = phi / (2 * PI);
	norm->v = theta / PI;
	norm->u = ft_minmax(norm->u, 0.0, 1.0);
	norm->v = 1.0 - ft_minmax(norm->v, 0.0, 1.0);
}
