/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:35:09 by chanson           #+#    #+#             */
/*   Updated: 2023/05/17 21:03:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_aabb	cylinder_aabb_box(t_cylinder cyl)
{
	t_aabb	bound_box;
	t_vec3	down;
	t_vec3	up;
	double	a;
	double	b;

	a = cyl.c_c.x + cyl.c_c.y + cyl.c_c.z;
	b = cyl.c_h.x + cyl.c_h.y + cyl.c_h.z;
	if (a < b)
	{
		down = cyl.c_c;
		up = cyl.c_h;
	}
	else
	{
		down = cyl.c_h;
		up = cyl.c_c;
	}
	bound_box.minimum = sub_vec3(down, \
		vec3init(cyl.radius, cyl.radius, cyl.radius));
	bound_box.maximum = add_vec3(up, \
		vec3init(cyl.radius, cyl.radius, cyl.radius));
	return (bound_box);
}
