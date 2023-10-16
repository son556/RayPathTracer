/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:17:44 by chanson           #+#    #+#             */
/*   Updated: 2023/04/22 13:49:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

t_vec3	vec3init(double x, double y, double z)
{
	t_vec3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_vec3	add_vec3(t_vec3 v1, t_vec3 v2)
{
	return (vec3init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec3	sub_vec3(t_vec3 v1, t_vec3 v2)
{
	return (vec3init(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec3	mul_vec3(t_vec3 v1, double t)
{
	return (vec3init(v1.x * t, v1.y * t, v1.z * t));
}

t_vec3	div_vec3(t_vec3 v1, double t)
{
	return (vec3init(v1.x / t, v1.y / t, v1.z / t));
}
