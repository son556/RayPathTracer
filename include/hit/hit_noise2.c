/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_noise2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:14:27 by chanson           #+#    #+#             */
/*   Updated: 2023/05/30 15:04:06 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	noise_(t_norm norm, t_vec3 (*c)[2][2][2], int *ijk)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			k = -1;
			while (++k < 2)
				(*c)[i][j][k] = \
				norm.noise.ranfloat[norm.noise.p_x[(ijk[0] + i) & 255] ^ \
							norm.noise.p_y[(ijk[1] + j) & 255] ^ \
							norm.noise.p_z[(ijk[2] + k) & 255]];
		}
	}
}

double	noise(t_norm norm)
{
	t_vec3	c[2][2][2];
	int		ijk[3];

	norm.noise.u = norm.hit.x - floor(norm.hit.x);
	norm.noise.v = norm.hit.y - floor(norm.hit.y);
	norm.noise.w = norm.hit.z - floor(norm.hit.z);
	norm.noise.u = norm.noise.u * norm.noise.u * (3 - 2 * norm.noise.u);
	norm.noise.v = norm.noise.v * norm.noise.v * (3 - 2 * norm.noise.v);
	norm.noise.w = norm.noise.w * norm.noise.w * (3 - 2 * norm.noise.w);
	ijk[0] = (int)(floor(norm.hit.x));
	ijk[1] = (int)(floor(norm.hit.y));
	ijk[2] = (int)(floor(norm.hit.z));
	noise_(norm, &c, ijk);
	return (trilinear_interp(c, norm.noise.u, norm.noise.v, norm.noise.w));
}

static double	turb(t_norm norm)
{
	double	accum;
	t_norm	temp_p;
	double	weight;
	int		i;

	accum = 0.0;
	temp_p = norm;
	weight = 1.0;
	i = -1;
	while (++i < 7)
	{
		accum += weight * noise(temp_p);
		weight *= 0.5;
		temp_p.hit = mul_vec3(temp_p.hit, 2);
	}
	return (accum);
}

t_color3	noise_color(t_norm norm, double scale)
{
	t_color3	color;
	double		z;

	z = norm.hit.z;
	norm.hit = mul_vec3(norm.hit, scale);
	color = mul_vec3(vec3init(1, 1, 1), \
		0.5 * (1 + sin(scale * z + 10 * turb(norm))));
	return (color);
}
