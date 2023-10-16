/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_aabb2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:19:22 by chanson           #+#    #+#             */
/*   Updated: 2023/05/20 15:26:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_aabb	make_surrounding_box(t_aabb box1, t_aabb box2)
{
	t_vec3	small;
	t_vec3	big;

	small = vec3init(fmin(box1.minimum.x, box2.minimum.x), \
					fmin(box1.minimum.y, box2.minimum.y), \
					fmin(box1.minimum.z, box2.minimum.z));
	big = vec3init(fmax(box1.maximum.x, box2.maximum.x), \
					fmax(box1.maximum.y, box2.maximum.y), \
					fmax(box1.maximum.z, box2.maximum.z));
	return (make_aabb_box(small, big));
}

int	left_right_box(t_aabb box1, t_aabb box2, int axis)
{
	if (axis == 0)
	{
		if (ft_abs(box1.minimum.x) > ft_abs(box2.minimum.x))
			return (1);
	}
	else if (axis == 1)
	{
		if (ft_abs(box1.minimum.y) > ft_abs(box2.minimum.y))
			return (1);
	}
	else
		if (ft_abs(box1.minimum.z) > ft_abs(box2.minimum.z))
			return (1);
	return (0);
}

static void	copy_sorted_arr(t_obj *obj, t_obj *sorted, t_vec3 start_mid_end)
{
	int	i;

	i = start_mid_end.x;
	while (i <= start_mid_end.z)
	{
		obj[i] = sorted[i];
		i++;
	}
}

static void	merge_obj(t_obj *obj, t_vec3 start_mid_end, int axis)
{
	int				i;
	int				j;
	int				z;
	static t_obj	sorted[1000];

	i = start_mid_end.x;
	j = start_mid_end.y + 1;
	z = start_mid_end.x;
	while (i <= start_mid_end.y && j <= start_mid_end.z)
	{
		if (left_right_box(obj[i].bound_box, obj[j].bound_box, axis))
			sorted[z++] = obj[j++];
		else
			sorted[z++] = obj[i++];
	}
	if (i > start_mid_end.y)
		while (j <= start_mid_end.z)
			sorted[z++] = obj[j++];
	else if (j > start_mid_end.z)
		while (i <= start_mid_end.y)
			sorted[z++] = obj[i++];
	copy_sorted_arr(obj, sorted, start_mid_end);
}

void	sort_obj_by_axis(t_obj *obj, int start, int end, int axis)
{
	int		mid;
	t_vec3	start_mid_end;

	if (start < end)
	{
		mid = (start + end) / 2;
		sort_obj_by_axis(obj, start, mid, axis);
		sort_obj_by_axis(obj, mid + 1, end, axis);
		start_mid_end.x = start;
		start_mid_end.y = mid;
		start_mid_end.z = end;
		merge_obj(obj, start_mid_end, axis);
	}
}
