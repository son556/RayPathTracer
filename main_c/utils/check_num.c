/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:14:27 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 19:50:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	check_num(char *str, char *err_m)
{
	int		i;
	int		cnt;
	double	result;

	i = 0;
	cnt = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '.')
			++cnt;
		if (i == 0 && str[i] != '.' && !ft_isdigit(str[i]) && str[i] != '+' \
			&& str[i] != '-')
			ft_strexit(err_m);
		if (i != 0 && str[i] != '.' && !ft_isdigit(str[i]))
			ft_strexit(err_m);
		++i;
	}
	if (cnt > 1)
		ft_strexit(err_m);
	result = ft_atof(str);
	return (result);
}
