/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:58 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 20:01:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_norm	hit_sphere(t_sphere sph, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	disc.ac = sub_vec3(ray.point, sph.center);
	disc.a = dot_vec3(ray.direction, ray.direction);
	disc.b = dot_vec3(disc.ac, ray.direction);
	disc.c = dot_vec3(disc.ac, disc.ac) - ft_pow(sph.radius);
	disc.discrim = disc.b * disc.b - disc.a * disc.c;
	norm.root = 0;
	if (disc.discrim < 0)
		return (norm);
	disc.root = (-disc.b - sqrt(disc.discrim)) / disc.a;
	if (disc.root < 1e-5 || disc.root > t_max)
	{
		disc.root = (-disc.b + sqrt(disc.discrim)) / disc.a;
		if (disc.root < 1e-5 || disc.root > t_max)
			return (norm);
	}
	norm.root = disc.root;
	norm.n_vec = div_vec3(sub_vec3(ray_at(ray, norm.root), sph.center), \
		sph.radius);
	return (norm);
}

t_aabb	sphere_aabb_box(t_sphere sph)
{
	t_aabb	sph_box;

	sph_box.minimum = sub_vec3(sph.center, \
		vec3init(sph.radius, sph.radius, sph.radius));
	sph_box.maximum = add_vec3(sph.center, \
		vec3init(sph.radius, sph.radius, sph.radius));
	return (sph_box);
}

t_norm	hit_plane(t_plane pln, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	if (dot_vec3(ray.direction, pln.n_vec) == 0)
	{
		norm.root = 0;
		return (norm);
	}
	if (dot_vec3(sub_vec3(ray.point, pln.center), pln.n_vec) == 0)
	{
		norm.root = 0;
		return (norm);
	}
	disc.ac = sub_vec3(ray.point, pln.center);
	disc.a = -1 * dot_vec3(disc.ac, pln.n_vec);
	disc.b = dot_vec3(ray.direction, pln.n_vec);
	disc.root = disc.a / disc.b;
	if (disc.root < 1e-5 || disc.root > t_max)
		norm.root = 0;
	norm.root = disc.root;
	norm.n_vec = pln.n_vec;
	return (norm);
}
