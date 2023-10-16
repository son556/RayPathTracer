/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 15:05:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"
#include <stdio.h>

static void	find_norm(t_norm *no, t_para para, t_vec3 hit, t_discrim *d)
{
	t_vec3	mid;
	t_vec3	hit2;
	double	t;

	no->root = d->root;
	t = -1 * dot_vec3(sub_vec3(para.pl.center, hit), para.pl.n_vec);
	hit2 = add_vec3(hit, mul_vec3(mul_vec3(para.pl.n_vec, -1), t));
	mid = mul_vec3(add_vec3(para.cen, hit2), 0.5);
	no->n_vec = normalize_vec3(sub_vec3(mid, para.cen));
}

static t_norm	validation_para(t_discrim *d, t_ray ray, t_para p, double t_max)
{
	t_vec3	h;
	t_norm	norm;
	double	t;

	norm.root = 0;
	t = dot_vec3(p.pl.n_vec, sub_vec3(ray_at(ray, d->root), p.cen));
	if (t > 0 && t > p.len - (p.len_cc * 0.5))
	{
		h = add_vec3(p.cen, mul_vec3(p.pl.n_vec, p.len - p.len_cc * 0.5));
		t = dot_vec3(p.pl.n_vec, ray.direction);
		if (t < 1e-5 && t > -1e-5)
			return (norm);
		t = -1 * dot_vec3(sub_vec3(ray.point, h), p.pl.n_vec) / t;
		if (t < 0.001 || t > t_max)
			return (norm);
		if (len_vec3(sub_vec3(ray_at(ray, t), h)) > p.r)
			return (norm);
		norm.root = t;
		norm.n_vec = p.pl.n_vec;
	}
	else
		find_norm(&norm, p, ray_at(ray, d->root), d);
	return (norm);
}

static int	para_plane(t_para pa, t_norm *no, t_ray ray, double t_max)
{
	t_vec3	hit;
	t_vec3	cen;
	double	t;

	if (dot_vec3(ray.direction, pa.pl.n_vec) >= 0)
		return (0);
	cen = add_vec3(pa.cen, mul_vec3(pa.pl.n_vec, pa.len - pa.len_cc * 0.5));
	if (dot_vec3(sub_vec3(cen, ray.point), pa.pl.n_vec) >= 0)
		return (0);
	t = dot_vec3(ray.direction, pa.pl.n_vec);
	if (t < 1e-5 && t > -1e-5)
		return (0);
	t = -1 * dot_vec3(sub_vec3(ray.point, cen), pa.pl.n_vec) / t;
	if (t < 0.001 || t > t_max)
		return (0);
	hit = ray_at(ray, t);
	if (len_vec3(sub_vec3(hit, cen)) > pa.r)
		return (0);
	no->root = t;
	no->n_vec = pa.pl.n_vec;
	return (1);
}

static int	para_range_check(t_discrim *disc, double t_max)
{
	double	n1;
	double	n2;

	n1 = (-1 * disc->b - sqrt(disc->discrim)) / disc->a;
	n2 = (-1 * disc->b + sqrt(disc->discrim)) / disc->a;
	if (n1 > n2)
		disc->root = n2;
	else
		disc->root = n1;
	if (disc->root < 0.001 || disc->root > t_max)
		return (0);
	return (1);
}

t_norm	hit_paraboloid(t_para para, t_ray ray, double t_max)
{
	t_norm		norm;
	t_discrim	disc;

	norm.root = 0;
	if (para_plane(para, &norm, ray, t_max))
		return (norm);
	disc.a = ft_pow(dot_vec3(para.pl.n_vec, ray.direction)) - \
		dotself_vec3(ray.direction);
	disc.b = dot_vec3(ray.direction, para.pl.n_vec) * \
			dot_vec3(ray.point, para.pl.n_vec) - \
			dot_vec3(ray.direction, para.pl.n_vec) * \
			dot_vec3(para.pl.center, para.pl.n_vec) - \
			dot_vec3(ray.point, ray.direction) + \
			dot_vec3(ray.direction, para.cen);
	disc.c = dot_vec3(ray.point, para.pl.n_vec) - \
			dot_vec3(para.pl.center, para.pl.n_vec);
	disc.c = ft_pow(disc.c) - dotself_vec3(ray.point);
	disc.c += 2 * dot_vec3(para.cen, ray.point) - dotself_vec3(para.cen);
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	if (disc.discrim < 0)
		return (norm);
	if (para_range_check(&disc, t_max) == 0)
		return (norm);
	return (validation_para(&disc, ray, para, t_max));
}
