/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:14:45 by chanson           #+#    #+#             */
/*   Updated: 2023/05/06 17:29:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	dotself_vec3(t_vec3 v)
{
	return (dot_vec3(v, v));
}

t_vec3x3	vec3x3init(t_vec3 v_x, t_vec3 v_y, t_vec3 v_z)
{
	t_vec3x3	vec3x3;

	vec3x3.v_x = v_x;
	vec3x3.v_y = v_y;
	vec3x3.v_z = v_z;
	return (vec3x3);
}

t_vec3	vec3x3_x_vec3(t_vec3x3 vec3x3, t_vec3 vec)
{
	t_vec3	result;

	result.x = dot_vec3(vec3x3.v_x, vec);
	result.y = dot_vec3(vec3x3.v_y, vec);
	result.z = dot_vec3(vec3x3.v_z, vec);
	return (result);
}

t_vec3x3	transpose_vec3x3(t_vec3x3 vec3x3)
{
	t_vec3x3	vec3x3_t;

	vec3x3_t.v_x = vec3init(vec3x3.v_x.x, vec3x3.v_y.x, vec3x3.v_z.x);
	vec3x3_t.v_y = vec3init(vec3x3.v_x.y, vec3x3.v_y.y, vec3x3.v_z.y);
	vec3x3_t.v_z = vec3init(vec3x3.v_x.z, vec3x3.v_y.z, vec3x3.v_z.z);
	return (vec3x3_t);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
