/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_noise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:26:37 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 21:56:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_color3	check_color(double u, double v, t_vec3 point, t_color3 col)
{
	double	sine;

	(void)u;
	(void)v;
	sine = sin(9 * point.x) * sin(9 * point.y) * sin(9 * point.z);
	if (sine < 0)
		return (col);
	else
		return (vec3init(0.9, 0.9, 0.9));
}

static void	permute(int *perm, int n)
{
	int	i;
	int	target;
	int	tmp;

	i = n;
	while (--i > 0)
	{
		target = (int)(drand48() * (i + 1));
		tmp = perm[i];
		perm[i] = perm[target];
		perm[target] = tmp;
	}
}

void	perm_and_ranfloat(int *p_x, int *p_y, int *p_z, t_vec3 *ranfloat)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		p_x[i] = i;
		p_y[i] = i;
		p_z[i] = i;
		ranfloat[i] = normalize_vec3(random_minmax_vec3(-1, 1.0));
	}
	permute(p_x, 256);
	permute(p_y, 256);
	permute(p_z, 256);
}

static double	accum_(t_vec3 weight, t_vec3 c[2][2][2], int *idx, double *uvw)
{
	double	accum;

	accum = (idx[0] * uvw[0] + (1 - idx[0]) * (1 - uvw[0])) * \
			(idx[1] * uvw[1] + (1 - idx[1]) * (1 - uvw[1])) * \
			(idx[2] * uvw[2] + (1 - idx[2]) * (1 - uvw[2])) * \
			dot_vec3(c[idx[0]][idx[1]][idx[2]], weight);
	return (accum);
}

double	trilinear_interp(t_vec3 c[2][2][2], double u, double v, double w)
{
	double	accum;
	t_vec3	weight;
	int		idx[3];
	double	uvw[3];

	idx[0] = -1;
	accum = 0.0;
	uvw[0] = u * u * (3 - 2 * u);
	uvw[1] = v * v * (3 - 2 * v);
	uvw[2] = w * w * (3 - 2 * w);
	while (++idx[0] < 2)
	{
		idx[1] = -1;
		while (++idx[1] < 2)
		{
			idx[2] = -1;
			while (++idx[2] < 2)
			{
				weight = vec3init(u - idx[0], v - idx[1], w - idx[2]);
				accum += accum_(weight, c, idx, uvw);
			}
		}
	}
	return (accum);
}
