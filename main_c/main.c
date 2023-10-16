/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 20:38:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	thread_start(t_list_pth	*list)
{
	t_thread	thread_list[6];
	t_norm		norm;
	int			i;

	i = -1;
	norm.background = vec3init(0, 0, 0);
	perm_and_ranfloat(norm.noise.p_x, norm.noise.p_y, \
		norm.noise.p_z, norm.noise.ranfloat);
	set_thread_lst(thread_list, list, norm);
	while (++i < 6)
		pthread_create(&(thread_list[i].thread), NULL, \
			&draw, (void *)&(thread_list[i]));
	i = -1;
	while (++i < 6)
		pthread_join(thread_list[i].thread, NULL);
	pthread_mutex_destroy(&(list->key));
	pthread_mutex_destroy(&(list->key_draw));
}

int	main(int argc, char **argv)
{
	t_list_pth	list;
	t_obj		*obj;

	obj = check_scene(argc, argv, &list);
	obj->mlx.mlx = &(list.m.mlx);
	texture_img(&(obj->mlx));
	list.first = NULL;
	set_task_list(&list, list.m.arr_cnt, obj);
	thread_start(&list);
	mlx_key_hook(list.m.mlx.win, key_hook, &(list.m.mlx));
	mlx_hook(list.m.mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(list.m.mlx.mlx);
	return (0);
}
