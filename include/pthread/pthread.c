/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:10:32 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 20:39:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pthread.h"

static void	set_task(t_task *task, int start, int end)
{
	task->start = start;
	task->end = end;
	task->next = NULL;
}

void	set_task_list(t_list_pth *list, int arr_cnt, t_obj *o_list)
{
	t_task	*task;
	int		i;
	int		start;
	int		end;

	i = -1;
	start = 0;
	end = 34;
	pthread_mutex_init(&(list->key), 0);
	pthread_mutex_init(&(list->key_draw), 0);
	list->point_x = list->m.point_x;
	list->m.arr_cnt = arr_cnt;
	list->obj_list = o_list;
	while (++i < 20)
	{
		task = (t_task *)malloc(sizeof(t_task));
		set_task(task, start, end);
		if (list->first == NULL)
			list->first = task;
		else
			list->last->next = task;
		list->last = task;
		start += 35;
		end += 35;
	}
}

t_task	out_task(t_list_pth *list)
{
	t_task	tmp;
	t_task	*tmp_task;

	pthread_mutex_lock(&(list->key));
	tmp_task = list->first;
	if (list->first == NULL)
	{
		list->first = NULL;
		tmp.start = -1;
	}
	else
	{
		tmp.start = list->first->start;
		tmp.end = list->first->end;
		list->first = list->first->next;
	}
	free(tmp_task);
	pthread_mutex_unlock(&(list->key));
	return (tmp);
}

void	set_thread_lst(t_thread *thr_lst, t_list_pth *list, t_norm norm)
{
	int		i;

	i = -1;
	while (++i < 6)
	{
		thr_lst[i].list = list;
		thr_lst[i].thread_idx = i;
		thr_lst[i].norm.background = norm.background;
		thr_lst[i].norm.light.color = norm.light.color;
		thr_lst[i].norm.noise = norm.noise;
	}
}
