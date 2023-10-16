/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:08:35 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 17:50:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static t_color3	def_norm(t_norm *norm, t_norm temp, t_ray ray, t_obj obj)
{
	t_color3	color;

	norm->root = temp.root;
	norm->n_vec = temp.n_vec;
	norm->hit = ray_at(ray, norm->root);
	norm->front = front_or_back(ray, *norm);
	if (norm->front == 0)
		norm->n_vec = mul_vec3(norm->n_vec, -1);
	norm->light.ratio = dot_vec3(norm->n_vec, \
		normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
	norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
	norm->light.ratio += 0.3;
	if (norm->light.ratio > 1)
		norm->light.ratio = 1;
	color = mul_vec3(obj.color, norm->light.ratio);
	norm->t_max = temp.root;
	return (color);
}

static t_color3	define_background_color(t_ray ray)
{
	double		t;
	t_color3	color;

	t = 0.5 * (ray.direction.y + 1.0);
	color = vec3init(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0);
	return (color);
}

t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_vec3	color;
	int		i;
	t_norm	tmp_n;

	tmp_n.t_max = INFINITY;
	norm->t_max = tmp_n.t_max;
	i = -1;
	color.x = -1000;
	tmp_n = *norm;
	while (++i < n)
	{
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		tmp_n.t_max = norm->t_max;
		if (tmp_n.root > 0.0)
		{
			color = def_norm(norm, tmp_n, ray, obj[i]);
			tmp_n.t_max = norm->t_max;
			if (shade(*norm, obj, n, i))
				color = mul_vec3(obj[i].color, 0.3);
		}
	}
	if (color.x == -1000)
		color = define_background_color(ray);
	return (color);
}

/*no bvh*/
int	obj_arr_hit(t_obj *obj, t_ray ray, t_norm *norm, int n)
{
	t_norm		tmp_n;
	int			i;

	norm->t_max = INFINITY;
	i = -1;
	norm->hit_idx = -1;
	while (++i < n)
	{
		tmp_n.t_max = norm->t_max;
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		if (tmp_n.root != 0)
		{
			norm->t_max = tmp_n.root;
			norm->n_vec = tmp_n.n_vec;
			norm->front = front_or_back(ray, *norm);
			if (norm->front == 0)
				norm->n_vec = mul_vec3(norm->n_vec, -1);
			norm->root = tmp_n.root;
			norm->hit = ray_at(ray, norm->root);
			norm->material = obj[i].material;
			norm->hit_idx = i;
		}
	}
	return (norm->hit_idx);
}
	// if (bvh_hit(&temp, ray, obj) != -1)
	// if (obj_arr_hit(obj, ray, &temp, n) != -1)

t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_norm		temp;
	t_color3	col;
	t_ray		new_ray;

	temp = *norm;
	if (norm->depth <= 0)
		return (vec3init(0, 0, 0));
	if (obj_arr_hit(obj, ray, &temp, n) != -1)
	{
		norm->depth -= 1;
		col = obj[temp.hit_idx].color;
		if (obj[temp.hit_idx].texture == CHECK_TEXTURE)
			col = check_color(norm->u, norm->v, temp.hit, col);
		else if (obj[temp.hit_idx].texture == NOISE_TEXTURE)
			col = noise_color(temp, 4);
		if (temp.material == METAL)
			new_ray = specular_ray(temp, ray, obj[temp.hit_idx].fuzz);
		else if (temp.material == GLASS)
			new_ray = refract_ray(temp, ray, obj[temp.hit_idx].ref_idx);
		else
			new_ray = diffuse_ray(temp, ray);
		return (vec3_x_vec3(test_color(new_ray, obj, norm, n), col));
	}
	return (define_background_color(ray));
}
