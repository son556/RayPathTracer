/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:09:50 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 16:12:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	def_color(t_color3 *col, t_obj *obj, t_norm *temp, t_norm norm)
{
	if (obj[temp->hit_idx].texture == CHECK_TEXTURE)
		*col = check_color(norm.u, norm.v, temp->hit, obj[temp->hit_idx].color);
	else if (obj[temp->hit_idx].texture == NOISE_TEXTURE)
		*col = noise_color(*temp, 4);
	else if (obj[temp->hit_idx].texture == IMAGE_TEXTURE)
		*col = img_color(temp, obj);
	else
		*col = obj[temp->hit_idx].color;
}

static t_ray	def_new_ray(t_ray ray, t_obj *obj, t_norm temp)
{
	t_ray	new_ray;

	if (temp.material == METAL)
		new_ray = specular_ray(temp, ray, obj[temp.hit_idx].fuzz);
	else if (temp.material == GLASS)
		new_ray = refract_ray(temp, ray, obj[temp.hit_idx].ref_idx);
	else
		new_ray = diffuse_ray(temp, ray);
	return (new_ray);
}

t_color3	light_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
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
		if (obj[temp.hit_idx].material == LIGHT)
			return (mul_vec3(obj[temp.hit_idx].light.color, \
				obj[temp.hit_idx].light.ratio));
		def_color(&col, obj, &temp, *norm);
		new_ray = def_new_ray(ray, obj, temp);
		return (vec3_x_vec3(light_color(new_ray, obj, norm, n), col));
	}
	return (norm->background);
}
