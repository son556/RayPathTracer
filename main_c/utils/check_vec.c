/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:10:46 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 13:25:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vec3	check_vec(char *str, char *err_m)
{
	char	**split;
	int		size;
	t_vec3	result;

	split = ft_split(str, ',');
	size = 0;
	while (split[size])
		++size;
	if (size != 3)
		ft_strexit(err_m);
	result.x = check_num(split[0], err_m);
	result.y = check_num(split[1], err_m);
	result.z = check_num(split[2], err_m);
	free_split(split);
	return (result);
}
