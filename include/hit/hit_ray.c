/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:31:43 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 17:53:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_norm	find_hit_function(t_ray ray, t_obj obj, double t_max)
{
	if (obj.type == SPHERE)
		return (hit_sphere(obj.sphere, ray, t_max));
	if (obj.type == CYLINDER)
		return (hit_cylinder(obj.cylinder, ray, t_max));
	if (obj.type == PLANE)
		return (hit_plane(obj.plane, ray, t_max));
	if (obj.type == CUBE)
		return (hit_cube(obj.cube, ray, t_max, &obj.color));
	if (obj.type == CONE)
		return (hit_cone(obj.cone, ray, t_max));
	if (obj.type == XYZ_PLANE)
		return (hit_xyz_pl(ray, obj.xyz_pl, t_max));
	return (hit_paraboloid(obj.para, ray, t_max));
}

int	shade(t_norm norm, t_obj *obj, int n, int m)
{
	t_norm	temp;
	t_ray	ray;
	double	t_max;
	int		i;

	(void)m;
	ray.point = add_vec3(norm.hit, mul_vec3(norm.n_vec, 1e-5));
	ray.direction = normalize_vec3(sub_vec3(norm.light.point, ray.point));
	t_max = len_vec3(sub_vec3(norm.hit, norm.light.point));
	i = -1;
	while (++i < n)
	{
		temp = find_hit_function(ray, obj[i], t_max);
		if (temp.root > 0.0)
			return (1);
	}
	return (0);
}

int	front_or_back(t_ray ray, t_norm norm)
{
	double	dif;

	dif = dot_vec3(ray.direction, norm.n_vec);
	if (dif < 0)
		return (1);
	return (0);
}

t_ray	diffuse_ray(t_norm norm, t_ray ray)
{
	t_ray	new_ray;
	t_vec3	temp;

	new_ray.point = norm.hit;
	temp = random_minmax_vec3(-1, 1);
	temp = add_vec3(norm.n_vec, temp);
	if (ft_abs(temp.x) < 1e-5 && ft_abs(temp.y) < 1e-5 && ft_abs(temp.z) < 1e-5)
		new_ray.direction = ray.direction;
	else
		new_ray.direction = normalize_vec3(temp);
	return (new_ray);
}

t_ray	specular_ray(t_norm norm, t_ray ray, double fuzz)
{
	t_ray	new_ray;
	t_vec3	specular_dir;

	new_ray.point = norm.hit;
	specular_dir = add_vec3(ray.direction, mul_vec3(norm.n_vec, \
		-2 * dot_vec3(ray.direction, norm.n_vec)));
	if (fuzz > 1)
		fuzz = 1.0;
	specular_dir = add_vec3(specular_dir, \
		mul_vec3(random_in_unit_sphere(), fuzz));
	new_ray.direction = normalize_vec3(specular_dir);
	return (new_ray);
}
