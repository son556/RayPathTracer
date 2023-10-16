/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:27:17 by chanson           #+#    #+#             */
/*   Updated: 2023/06/01 12:33:23 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static t_vec3	color_vec3(int color)
{
	t_vec3	result;

	result.x = ft_min(color & (0xFF << 16), (0xFF << 16)) / (0xFF << 16);
	result.y = ft_min(color & (0xFF << 8), (0xFF << 8)) / (0xFF << 8);
	result.z = ft_min(color & (0xFF), 255) / 255;
	return (result);
}

t_color3	img_color(t_norm *norm, t_obj *obj)
{
	int			w;
	int			h;
	t_color3	col;
	t_vec3		normal;

	if (obj[norm->hit_idx].type != SPHERE)
		return (obj[norm->hit_idx].color);
	get_uv(norm, norm->hit, obj[norm->hit_idx].sphere.center);
	w = (int)(obj->mlx.block_c.width * norm->u);
	h = (int)(obj->mlx.block_c.height * norm->v);
	col = color_vec3(my_mlx_pixel_get(&obj->mlx.block_c.data, w, h));
	w = (int)(obj->mlx.block_b.width * norm->u);
	h = (int)(obj->mlx.block_b.height * norm->v);
	normal = color_vec3(my_mlx_pixel_get(&obj->mlx.block_b.data, w, h));
	normal = sub_vec3(mul_vec3(normal, 2), vec3init(1, 1, 1));
	norm->n_vec = add_vec3(norm->n_vec, normal);
	return (col);
}
