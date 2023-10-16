/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_aabb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:02:06 by chanson           #+#    #+#             */
/*   Updated: 2023/05/20 19:16:09 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static double	*hit_aabb_arr(t_aabb box, t_ray ray)
{
	double	*aabb_arr;
	t_ray	tmp_ray;

	tmp_ray = ray;
	aabb_arr = (double *)malloc(sizeof(double) * 6);
	if (tmp_ray.direction.x == 0)
		tmp_ray.direction.x = 1e-5;
	if (tmp_ray.direction.y == 0)
		tmp_ray.direction.y = 1e-5;
	if (tmp_ray.direction.z == 0)
		tmp_ray.direction.z = 1e-5;
	aabb_arr[0] = (box.minimum.x - ray.point.x) / tmp_ray.direction.x;
	aabb_arr[1] = (box.maximum.x - ray.point.x) / tmp_ray.direction.x;
	aabb_arr[2] = (box.minimum.y - ray.point.y) / tmp_ray.direction.y;
	aabb_arr[3] = (box.maximum.y - ray.point.y) / tmp_ray.direction.y;
	aabb_arr[4] = (box.minimum.z - ray.point.z) / tmp_ray.direction.z;
	aabb_arr[5] = (box.maximum.z - ray.point.z) / tmp_ray.direction.z;
	return (aabb_arr);
}

int	hit_aabb(t_ray ray, double t_max, double t_min, t_aabb box)
{
	double	t1;
	double	t2;
	double	*aabb_arr;
	int		i;

	aabb_arr = hit_aabb_arr(box, ray);
	i = 0;
	while (i <= 4)
	{
		t1 = fmin(aabb_arr[i], aabb_arr[i + 1]);
		t2 = fmax(aabb_arr[i], aabb_arr[i + 1]);
		t_min = fmax(t1, t_min);
		t_max = fmin(t2, t_max);
		if (t_min >= t_max)
		{
			free(aabb_arr);
			return (0);
		}
		i += 2;
	}
	free(aabb_arr);
	return (1);
}

t_aabb	make_aabb_box(t_vec3 minimum, t_vec3 maximum)
{
	t_aabb	box;

	box.minimum = minimum;
	box.maximum = maximum;
	return (box);
}

static t_aabb	make_temp_box(t_obj obj)
{
	t_aabb	temp_box;

	if (obj.type == SPHERE)
		temp_box = sphere_aabb_box(obj.sphere);
	else if (obj.type == CYLINDER)
		temp_box = cylinder_aabb_box(obj.cylinder);
	else if (obj.type == CUBE)
		temp_box = cube_aabb_box(obj.cube);
	else if (obj.type == CONE)
		temp_box = cone_aabb_box(obj.cone);
	else
		temp_box = paraboloid_aabb_box(obj.para);
	return (temp_box);
}

t_aabb	make_out_box(t_obj *obj, int start, int end)
{
	int		i;
	int		first;
	t_aabb	temp_box;
	t_aabb	outbox;

	first = 1;
	i = start - 1;
	while (++i <= end)
	{
		temp_box = make_temp_box(obj[i]);
		if (first)
		{
			outbox = temp_box;
			first = 0;
		}
		else
			outbox = make_surrounding_box(temp_box, outbox);
	}
	return (outbox);
}
