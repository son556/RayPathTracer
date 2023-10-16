/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:15:40 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 19:48:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		++i;
	return (i);
}

static char	*_get_intger(char *str, int len)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		ft_strexit("Error\n");
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		++i;
	}
	result[i] = 0;
	return (result);
}

double	ft_atof(char *str)
{
	char	*ichar;
	int		len;
	double	temp;
	double	result;
	int		sign;

	len = _strlen(str);
	ichar = _get_intger(str, len);
	result = ft_atoi(ichar);
	free(ichar);
	ichar = ft_strchr(str, '.');
	if (ichar == 0)
		return (result);
	len = ft_strlen(ichar);
	temp = ft_atoi(ichar + 1);
	while (len > 1)
	{
		temp /= 10;
		--len;
	}
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	result += sign * temp;
	return (result);
}
