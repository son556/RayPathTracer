/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:28 by chanson           #+#    #+#             */
/*   Updated: 2023/06/03 22:02:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

static int	cnt_obj(char **argv)
{
	int		temp_fd;
	char	*gnl;
	int		cnt;

	temp_fd = open(argv[1], O_RDONLY);
	gnl = get_next_line(temp_fd);
	cnt = 0;
	while (gnl)
	{
		if (gnl[0] != 'A' && gnl[0] != 'C' && gnl[0] != '\n')
			cnt++;
		free(gnl);
		gnl = NULL;
		gnl = get_next_line(temp_fd);
	}
	close(temp_fd);
	return (cnt);
}

static	void	parsing_cam(char *str, t_list_pth *list)
{
	char	**strs;
	int		cnt;

	strs = ft_split(str, ' ');
	cnt = -1;
	while (1)
	{
		if (strs[++cnt] == NULL)
			break ;
	}
	if (cnt != 4)
		ft_strexit("error rt file: cam argv cnt\n");
	set_cam(&(list->m), check_vec(strs[1], "error rt file: cam point\n"), \
		check_vec(strs[2], "error rt file: cam vector\n"), \
		check_num(strs[3], "error rt file: cam fov"));
	free_split(strs);
}

static void	check_scene_(t_list_pth *list, t_obj *obj, char **argv)
{
	char	*gnl;
	int		fd;
	int		idx;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_strexit("Error\n");
	gnl = get_next_line(fd);
	idx = 0;
	while (gnl)
	{
		if (gnl[0] == 'C')
			parsing_cam(gnl, list);
		else if (gnl[0] != '\n')
		{
			parsing_rt(gnl, obj, idx);
			if (gnl[0] != 'A')
				idx++;
		}
		free(gnl);
		gnl = NULL;
		gnl = get_next_line(fd);
	}
	close(fd);
}

t_obj	*check_scene(int argc, char **argv, t_list_pth *list)
{
	char	*str;
	t_obj	*obj;

	if (argc != 2)
		ft_strexit("Error\n");
	str = ft_strchr(argv[1], '.');
	if (!str || ft_strncmp(str, ".rt", 4) != 0)
		ft_strexit("Error\n");
	list->m.arr_cnt = cnt_obj(argv);
	obj = (t_obj *)malloc(sizeof(t_obj) * (list->m.arr_cnt));
	check_scene_(list, obj, argv);
	return (obj);
}
