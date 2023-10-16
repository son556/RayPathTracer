/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:06:26 by chanson           #+#    #+#             */
/*   Updated: 2023/05/11 19:57:39 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	where_hit_cylinder_(t_vec3 *p, t_norm *n, t_cylinder c, double temp)
{
	if (temp > c.height)
	{
		n->n_vec = c.n_vec;
		*p = c.c_h;
	}
	else
	{
		n->n_vec = mul_vec3(c.n_vec, -1);
		*p = c.c_c;
	}
}

static double	where_hit_cylinder(t_norm *n, t_ray r, t_cylinder c, double t_m)
{
	double	temp;
	double	t;
	t_vec3	cen;
	t_vec3	hit;

	hit = ray_at(r, n->root);
	temp = dot_vec3(sub_vec3(hit, c.c_c), c.n_vec);
	n->n_vec = sub_vec3(hit, add_vec3(c.c_c, mul_vec3(c.n_vec, temp)));
	if (temp >= 0.0 && temp <= c.height)
		return (n->root);
	else
	{
		where_hit_cylinder_(&cen, n, c, temp);
		t = dot_vec3(r.direction, n->n_vec);
		if (t >= -1e-5 && t <= 1e-5)
			return (0);
		t = -dot_vec3(sub_vec3(r.point, cen), n->n_vec) / \
			dot_vec3(r.direction, n->n_vec);
		if (t < 1e-5 || t > t_m)
			return (0);
		temp = len_vec3(sub_vec3(ray_at(r, t), cen));
		if (temp > c.radius)
			return (0);
	}
	return (t);
}

int	range_in_hit(t_discrim *disc, double t_max)
{
	disc->root = (-disc->b - sqrt(disc->discrim)) / disc->a;
	if (disc->root < 0.001 || disc->root > t_max)
	{
		disc->root = (-disc->b + sqrt(disc->discrim)) / disc->a;
		if (disc->root < 0.001 || disc->root > t_max)
			return (0);
	}
	return (1);
}

static int	hit_top_down(t_norm *n, t_ray r, double t_m, t_cylinder cyl)
{
	t_vec3	cen;
	t_vec3	hit;
	double	t;

	n->root = 0;
	if (dot_vec3(r.direction, cyl.n_vec) > 0)
	{
		cen = cyl.c_c;
		n->n_vec = mul_vec3(cyl.n_vec, -1);
	}
	else
	{
		cen = cyl.c_h;
		n->n_vec = cyl.n_vec;
	}
	t = dot_vec3(n->n_vec, r.direction);
	if (t > -1e-5 && t < 1e-5)
		return (0);
	t = -dot_vec3(sub_vec3(r.point, cen), n->n_vec) / t;
	hit = ray_at(r, t);
	if (t < 1e-5 || t > t_m || len_vec3(sub_vec3(hit, cen)) > cyl.radius)
		return (0);
	n->root = t;
	return (1);
}

t_norm	hit_cylinder(t_cylinder cyl, t_ray ray, double t_max)
{
	t_discrim		disc;
	t_norm			norm;
	const t_vec3	w = sub_vec3(ray.point, cyl.c_c);

	norm.root = 0;
	if (hit_top_down(&norm, ray, t_max, cyl))
		return (norm);
	disc.a = dotself_vec3(ray.direction) - \
		ft_pow(dot_vec3(ray.direction, cyl.n_vec));
	disc.b = dot_vec3(ray.direction, w) - \
		(dot_vec3(ray.direction, cyl.n_vec) * dot_vec3(w, cyl.n_vec));
	disc.c = dotself_vec3(w) - ft_pow(dot_vec3(w, cyl.n_vec)) - \
		ft_pow(cyl.radius);
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	if (disc.discrim < 0)
		return (norm);
	if (disc.discrim <= 1e-5)
		if (ft_abs(dot_vec3(ray.direction, cyl.n_vec)) >= 1 - 1e-5)
			return (norm);
	if (!range_in_hit(&disc, t_max))
		return (norm);
	norm.root = disc.root;
	norm.root = where_hit_cylinder(&norm, ray, cyl, t_max);
	return (norm);
}
