/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:59:06 by chanson           #+#    #+#             */
/*   Updated: 2023/05/13 18:01:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

t_vec3x3	vec3x3_x_double(t_vec3x3 vec, double t)
{
	t_vec3x3	mat;

	mat.v_x = mul_vec3(vec.v_x, t);
	mat.v_y = mul_vec3(vec.v_y, t);
	mat.v_y = mul_vec3(vec.v_y, t);
	return (mat);
}

static t_vec3x3	make_factor_matrix(t_inverse_factor factor)
{
	t_vec3x3	mat;

	mat.v_x = vec3init(factor.c_11, factor.c_12, factor.c_13);
	mat.v_y = vec3init(factor.c_21, factor.c_22, factor.c_23);
	mat.v_z = vec3init(factor.c_31, factor.c_32, factor.c_33);
	return (mat);
}

t_vec3x3	inverse_vec3x3(t_vec3x3 vec)
{
	t_vec3x3			inv;
	t_inverse_factor	factor;

	inv = transpose_vec3x3(vec);
	factor.det_a = inv.v_x.x * (inv.v_y.y * inv.v_z.z - inv.v_z.y * inv.v_y.z);
	factor.det_a -= inv.v_x.y * (inv.v_y.x * inv.v_z.z - inv.v_x.z * inv.v_z.x);
	factor.det_a += inv.v_x.z * (inv.v_y.x * inv.v_z.y - inv.v_x.y * inv.v_z.x);
	factor.c_11 = inv.v_y.y * inv.v_z.z - inv.v_z.y * inv.v_y.z;
	factor.c_12 = -1 * (inv.v_x.y * inv.v_z.z - inv.v_z.y * inv.v_x.z);
	factor.c_13 = inv.v_x.y * inv.v_y.z - inv.v_y.y * inv.v_x.z;
	factor.c_21 = -1 * (inv.v_y.x * inv.v_z.z - inv.v_z.x * inv.v_y.z);
	factor.c_22 = inv.v_x.x * inv.v_z.z - inv.v_z.x * inv.v_x.z;
	factor.c_23 = -1 * (inv.v_x.x * inv.v_y.z - inv.v_y.x * inv.v_x.z);
	factor.c_31 = inv.v_y.x * inv.v_z.y - inv.v_z.x * inv.v_y.y;
	factor.c_32 = -1 * (inv.v_x.x * inv.v_z.y - inv.v_z.x * inv.v_x.y);
	factor.c_33 = inv.v_x.x * inv.v_y.y - inv.v_y.x * inv.v_x.y;
	inv = make_factor_matrix(factor);
	inv = vec3x3_x_double(inv, 1 / factor.det_a);
	return (inv);
}

double	getradian(int num)
{
	return (num * (PI / 180));
}

double	ft_minmax(double val, double t_min, double t_max)
{
	if (val < t_min)
		return (t_min);
	if (val > t_max)
		return (t_max);
	return (val);
}

void	display_vec3(t_vec3 vec)
{
	printf("%f %f %f\n", vec.x, vec.y, vec.z);
}

void	display_vec3x3(t_vec3x3 vec)
{
	display_vec3(vec.v_x);
	display_vec3(vec.v_y);
	display_vec3(vec.v_z);
}
