/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:21:32 by chanson           #+#    #+#             */
/*   Updated: 2023/05/30 14:52:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static double	where_hit_cone(t_discrim disc, t_ray ray, t_cone con, \
	t_norm *norm)
{
	double	temp;
	double	t;
	t_vec3	hit;

	hit = ray_at(ray, disc.root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	hit = add_vec3(con.c_h, mul_vec3(hit, con.height * con.c_cos));
	norm->n_vec = normalize_vec3(sub_vec3(hit, con.pl.center));
	temp = dot_vec3(sub_vec3(ray_at(ray, disc.root), con.c_h), con.n_vec);
	if (temp >= 0.0 && temp <= con.height)
		return (disc.root);
	else
		return (0);
	return (t);
}

static t_bool	line_in_cone(t_cone con, t_ray ray, t_discrim *disc)
{
	double	t;
	t_vec3	hit;

	disc->root = (-disc->b - sqrt(ft_pow(disc->b) - \
			disc->a * disc->c)) / disc->a;
	hit = ray_at(ray, disc->root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	t = dot_vec3(hit, con.n_vec);
	if (t <= con.c_cos + 1e-5 && t >= con.c_cos - 1e-5)
		return (1);
	disc->root = (-disc->b + sqrt(ft_pow(disc->b) - \
		disc->a * disc->c)) / disc->a;
	hit = ray_at(ray, disc->root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	t = dot_vec3(hit, con.n_vec);
	if (t <= con.c_cos + 1e-5 && t >= con.c_cos - 1e-5)
		return (1);
	return (0);
}

static t_norm	hit_cone_(t_cone con, t_ray ray, double t_max, t_discrim disc)
{
	t_norm	norm;

	norm.root = 0;
	if (!line_in_cone(con, ray, &disc))
		return (norm);
	if (disc.root < 1e-5 || disc.root > t_max)
		return (norm);
	disc.root = where_hit_cone(disc, ray, con, &norm);
	if (disc.root == 0)
		return (norm);
	norm.root = disc.root;
	return (norm);
}

static t_norm	hit_cone2(t_cone con, t_ray ray, double t_max)
{
	t_discrim	disc;
	double		m;
	t_norm		norm;

	m = ft_pow(con.radius) / ft_pow(con.height);
	disc.ac = sub_vec3(ray.point, con.c_h);
	disc.a = dotself_vec3(ray.direction) - (m + 1) * \
		ft_pow(dot_vec3(ray.direction, con.n_vec));
	disc.b = dot_vec3(ray.direction, disc.ac) - (m + 1) * \
		dot_vec3(ray.direction, con.n_vec) * dot_vec3(disc.ac, con.n_vec);
	disc.c = dotself_vec3(disc.ac) - \
		(m + 1) * ft_pow(dot_vec3(disc.ac, con.n_vec));
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	norm.root = 0;
	if (disc.discrim < 0)
		return (norm);
	return (hit_cone_(con, ray, t_max, disc));
}

t_norm	hit_cone(t_cone	con, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	norm.root = 0;
	disc.a = dot_vec3(ray.direction, con.pl.n_vec);
	if (disc.a > -1e-5 && disc.a < 1e-5)
		return (hit_cone2(con, ray, t_max));
	if (disc.a > 0)
	{
		disc.b = -dot_vec3(sub_vec3(ray.point, con.pl.center), \
			con.pl.n_vec) / dot_vec3(ray.direction, con.pl.n_vec);
		if (disc.b < 0 || disc.b > t_max)
			return (hit_cone2(con, ray, t_max));
		if (len_vec3(sub_vec3(ray_at(ray, disc.b), con.pl.center)) > con.radius)
			return (hit_cone2(con, ray, t_max));
		norm.root = disc.b;
		norm.n_vec = con.n_vec;
		return (norm);
	}
	return (hit_cone2(con, ray, t_max));
}
