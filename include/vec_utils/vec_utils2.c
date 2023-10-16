/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:29:45 by chanson           #+#    #+#             */
/*   Updated: 2023/05/02 19:32:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	dot_vec3(t_vec3 v1, t_vec3 v2)
{
	double	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

t_vec3	cross_vec3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

double	len_vec3(t_vec3 v1)
{
	double	result;

	result = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	return (sqrt(result));
}

t_vec3	normalize_vec3(t_vec3 v1)
{
	return (div_vec3(v1, len_vec3(v1)));
}

t_vec3x3	mul_vec3x3(t_vec3x3 v1, t_vec3x3 v2)
{
	t_vec3x3	result;

	result.v_x.x = dot_vec3(v1.v_x, vec3init(v2.v_x.x, v2.v_y.x, v2.v_z.x));
	result.v_x.y = dot_vec3(v1.v_x, vec3init(v2.v_x.y, v2.v_y.y, v2.v_z.y));
	result.v_x.z = dot_vec3(v1.v_x, vec3init(v2.v_x.z, v2.v_y.z, v2.v_z.z));
	result.v_y.x = dot_vec3(v1.v_y, vec3init(v2.v_x.x, v2.v_y.x, v2.v_z.x));
	result.v_y.y = dot_vec3(v1.v_y, vec3init(v2.v_x.y, v2.v_y.y, v2.v_z.y));
	result.v_y.z = dot_vec3(v1.v_y, vec3init(v2.v_x.z, v2.v_y.z, v2.v_z.z));
	result.v_z.x = dot_vec3(v1.v_z, vec3init(v2.v_x.x, v2.v_y.x, v2.v_z.x));
	result.v_z.y = dot_vec3(v1.v_z, vec3init(v2.v_x.y, v2.v_y.y, v2.v_z.y));
	result.v_z.z = dot_vec3(v1.v_z, vec3init(v2.v_x.z, v2.v_y.z, v2.v_z.z));
	return (result);
}
