/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_xyz_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:08:08 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 20:22:29 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	complete_xyz_pl(t_xyz_pl *xyz_pl, t_vec3 cen, double len, int xyz)
{
	if (xyz == 0)
	{
		xyz_pl->x0 = cen.x - len;
		xyz_pl->x1 = cen.x + len;
		xyz_pl->y0 = cen.y - len;
		xyz_pl->y1 = cen.y + len;
		xyz_pl->k = cen.z;
	}
	else if (xyz == 1)
	{
		xyz_pl->x0 = cen.x - len;
		xyz_pl->x1 = cen.x + len;
		xyz_pl->z0 = cen.z - len;
		xyz_pl->z1 = cen.z + len;
		xyz_pl->k = cen.y;
	}
	else
	{
		xyz_pl->y0 = cen.y - len;
		xyz_pl->y1 = cen.y + len;
		xyz_pl->z0 = cen.z - len;
		xyz_pl->z1 = cen.z + len;
		xyz_pl->k = cen.x;
	}
	xyz_pl->xyz = xyz;
}

static t_norm	hit_xy_pl(t_ray ray, t_xyz_pl pl, double t_max)
{
	t_norm	norm;
	double	t;
	double	x;
	double	y;

	norm.root = 0;
	t = (pl.k - ray.point.z) / ray.direction.z;
	if (t < 1e-5 || t > t_max)
		return (norm);
	x = ray.point.x + t * ray.direction.x;
	y = ray.point.y + t * ray.direction.y;
	if (x < pl.x0 || x > pl.x1 || y < pl.y0 || y > pl.y1)
		return (norm);
	norm.root = t;
	norm.n_vec = vec3init(0, 0, 1);
	return (norm);
}

static t_norm	hit_xz_pl(t_ray ray, t_xyz_pl pl, double t_max)
{
	t_norm	norm;
	double	t;
	double	x;
	double	z;

	norm.root = 0;
	t = (pl.k - ray.point.y) / ray.direction.y;
	if (t < 1e-5 || t > t_max)
		return (norm);
	x = ray.point.x + t * ray.direction.x;
	z = ray.point.z + t * ray.direction.z;
	if (x < pl.x0 || x > pl.x1 || z < pl.z0 || z > pl.z1)
		return (norm);
	norm.root = t;
	norm.n_vec = vec3init(0, 1, 0);
	return (norm);
}

static t_norm	hit_yz_pl(t_ray ray, t_xyz_pl pl, double t_max)
{
	t_norm	norm;
	double	t;
	double	y;
	double	z;

	norm.root = 0;
	t = (pl.k - ray.point.x) / ray.direction.x;
	if (t < 1e-5 || t > t_max)
		return (norm);
	y = ray.point.y + t * ray.direction.y;
	z = ray.point.z + t * ray.direction.z;
	if (z < pl.z0 || z > pl.z1 || y < pl.y0 || y > pl.y1)
		return (norm);
	norm.root = t;
	norm.n_vec = vec3init(1, 0, 0);
	return (norm);
}

t_norm	hit_xyz_pl(t_ray ray, t_xyz_pl pl, double t_max)
{
	if (pl.xyz == 0)
		return (hit_xy_pl(ray, pl, t_max));
	else if (pl.xyz == 1)
		return (hit_xz_pl(ray, pl, t_max));
	return (hit_yz_pl(ray, pl, t_max));
}
