/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:38:38 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 16:30:01 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

static void	_check_flag_(char **str, t_obj *obj, int idx)
{
	if (ft_strncmp(str[0], "xy", 3) == 0)
		parsing_xy(str, obj, idx);
	else if (ft_strncmp(str[0], "xz", 3) == 0)
		parsing_xz(str, obj, idx);
	else if (ft_strncmp(str[0], "yz", 3) == 0)
		parsing_yz(str, obj, idx);
	else if (ft_strncmp(str[0], "\n", 2) == 0)
		return ;
	else
		ft_strexit("Error\n");
}

static void	_check_flag(char **str, t_obj *obj, int idx)
{
	if (ft_strncmp(str[0], "A", 2) == 0)
		return ;
	else if (ft_strncmp(str[0], "L", 2) == 0)
		parsing_light(str, obj, idx);
	else if (ft_strncmp(str[0], "sp", 3) == 0)
		parsing_sp(str, obj, idx);
	else if (ft_strncmp(str[0], "cy", 3) == 0)
		parsing_cy(str, obj, idx);
	else if (ft_strncmp(str[0], "pl", 3) == 0)
		parsing_pl(str, obj, idx);
	else if (ft_strncmp(str[0], "cu", 3) == 0)
		parsing_cu(str, obj, idx);
	else if (ft_strncmp(str[0], "co", 3) == 0)
		parsing_co(str, obj, idx);
	else if (ft_strncmp(str[0], "pa", 3) == 0)
		parsing_pa(str, obj, idx);
	else
		_check_flag_(str, obj, idx);
}

void	parsing_rt(char *str, t_obj *obj, int idx)
{
	char	**split;

	split = NULL;
	split = ft_split(str, ' ');
	_check_flag(split, obj, idx);
	free_split(split);
}
