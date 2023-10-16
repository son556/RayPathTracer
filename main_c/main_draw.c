/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:46:51 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 22:01:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

static void	set_ray(t_main m, t_ray *ray, t_for_idx p)
{
	ray->point = m.origin;
	ray->direction.x = m.ll_corner.x + p.u * m.horizontal.x + \
		p.v * m.vertical.x - m.origin.x;
	ray->direction.y = m.ll_corner.y + p.u * m.horizontal.y + \
		p.v * m.vertical.y - m.origin.y;
	ray->direction.z = m.ll_corner.z + p.u * m.horizontal.z + \
		p.v * m.vertical.z - m.origin.z;
	ray->direction = normalize_vec3(ray->direction);
}

static void	draw_def_col(t_for_idx *p, t_thread *thr, t_list_pth *list)
{
	p->argb.x = sqrt(p->argb.x);
	p->argb.y = sqrt(p->argb.y);
	p->argb.z = sqrt(p->argb.z);
	p->argb = minmax_vec3(p->argb, 0, 1);
	p->color = argb_(0, (int)(p->argb.x * 255.999), \
		(int)(p->argb.y * 255.999), (int)(p->argb.z * 255.999));
	pthread_mutex_lock(&(thr->list->key_draw));
	mlx_pixel_put(list->m.mlx.mlx, list->m.mlx.win, \
		p->i, 700 - 1 - p->j, p->color);
	pthread_mutex_unlock(&(thr->list->key_draw));
}

static void	draw_anti(t_for_idx *p, t_ray *ray, t_thread *thr, t_list_pth *list)
{
	p->argb = vec3init(0, 0, 0);
	p->k = -1;
	while (++(p->k) < 3000)
	{
		p->u = (p->i + random_0_to_1()) / (thr->list->point_x - 1);
		p->v = (p->j + random_0_to_1()) / (thr->list->m.point_y - 1);
		ray->point = thr->list->m.origin;
		set_ray(list->m, ray, *p);
		thr->norm.depth = 15;
		thr->norm.hit_idx = -1;
		p->argb2 = light_color(*ray, list->obj_list, \
			&(thr->norm), list->m.arr_cnt);
		p->argb = add_vec3(p->argb, p->argb2);
	}
	p->argb = div_vec3(p->argb, 3000);
	draw_def_col(p, thr, list);
}

void	*draw(void *arg)
{
	t_thread	*thr;
	t_for_idx	p;
	t_task		task;
	t_ray		ray;
	t_list_pth	*list;

	thr = (t_thread *)arg;
	list = thr->list;
	while (1)
	{
		task = out_task(thr->list);
		if (task.start == -1)
			break ;
		p.j = task.end + 1;
		while (--(p.j) >= task.start)
		{
			p.i = -1;
			while (++(p.i) < list->point_x)
				draw_anti(&p, &ray, thr, list);
		}
	}
	return (0);
}
