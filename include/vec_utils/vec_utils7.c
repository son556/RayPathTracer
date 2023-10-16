/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:42:58 by chanson           #+#    #+#             */
/*   Updated: 2023/05/30 12:13:23 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

int	random_int(int min, int max)
{
	return ((int)random_min_max(min, max + 1));
}

t_vec3	vec3_x_vec3(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x * vec2.x;
	vec.y = vec1.y * vec2.y;
	vec.z = vec1.z * vec2.z;
	return (vec);
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	vec;

	while (1)
	{
		vec = random_minmax_vec3(-1, 1);
		if (len_vec3(vec) >= 1)
			continue ;
		return (vec);
	}
}

t_vec3	rotate_xy_vec3(t_vec3 vec3)
{
	t_vec3x3	rot_x;
	t_vec3x3	rot_y;
	t_vec3x3	rot;
	double		th;

	th = getradian(90);
	rot_x.v_x = vec3init(1, 0, 0);
	rot_x.v_y = vec3init(0, cos(th), -sin(th));
	rot_x.v_z = vec3init(0, sin(th), cos(th));
	rot_y.v_x = vec3init(cos(th), 0, -sin(th));
	rot_y.v_y = vec3init(0, 1, 0);
	rot_y.v_z = vec3init(sin(th), 0, cos(th));
	rot = mul_vec3x3(rot_y, rot_x);
	return (vec3x3_x_vec3(rot, vec3));
}

int	argb_(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
