/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:08:41 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/15 15:49:32 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_checkspace(unsigned char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	st_checksign(unsigned char c)
{
	if (c == '+')
		return (2);
	else if (c == '-')
		return (1);
	return (0);
}

static int	st_checkmaxmin(const char *str, const char *cmp, int sign)
{
	if (sign == -1 && (ft_strlen(str) >= 19))
	{
		if (ft_strncmp(str, cmp, 20) > 0)
			return (0);
	}
	else if (sign == 1 && (ft_strlen(str) >= 19))
	{
		if (ft_strncmp(str, cmp, 20) > 0)
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (st_checkspace(str[i]))
		++i;
	if (st_checksign(str[i]))
	{
		if (st_checksign(str[i]) == 1)
			sign *= -1;
		++i;
	}
	if (st_checkmaxmin(str + i, "9223372036854775808", sign) == 0)
		return (0);
	else if (st_checkmaxmin(str + i, "9223372036854775807", sign) == -1)
		return (-1);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		++i;
	}
	return (sign * result);
}
