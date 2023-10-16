/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:10:49 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 21:59:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_H
# define PTHREAD_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "./hit.h"
# include "./mlx_function.h"

typedef struct s_key
{
	pthread_mutex_t	key;
}	t_key;

typedef struct s_task
{
	int				start;
	int				end;
	struct s_task	*next;
}	t_task;

typedef struct s_for_idx
{
	int		i;
	int		j;
	int		k;
	double	u;
	double	v;
	t_vec3	argb;
	t_vec3	argb2;
	int		color;
}	t_for_idx;

typedef struct s_main
{
	t_vars	mlx;
	t_ray	ray;
	double	res_ratio;
	double	point_x;
	double	point_y;
	double	theta;
	double	h;
	double	vp_height;
	double	vp_width;
	t_vec3	look_from;
	t_vec3	vup;
	t_vec3	w_vec;
	t_vec3	u_vec;
	t_vec3	v_vec;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	origin;
	t_vec3	ll_corner;
	int		arr_cnt;
}	t_main;

typedef struct t_list_pth
{
	t_task			*first;
	t_task			*last;
	int				point_x;
	t_obj			*obj_list;
	pthread_mutex_t	key;
	pthread_mutex_t	key_draw;
	t_main			m;
}	t_list_pth;

typedef struct s_thread
{
	pthread_t	thread;
	t_task		*task;
	t_list_pth	*list;
	int			thread_idx;
	t_norm		norm;
}	t_thread;

void	set_task_list(t_list_pth *list, int arr_cnt, t_obj *o_list);
void	set_thread_lst(t_thread *thr_lst, t_list_pth *list, t_norm norm);
t_task	out_task(t_list_pth *list);
#endif