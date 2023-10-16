/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:06:07 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/11 20:17:52 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	st_fillresult(long long n, int *idx, char *result)
{
	if (n < 0)
	{
		result[*idx] = '-';
		++*idx;
		st_fillresult(-n, idx, result);
		return ;
	}
	if (n < 10)
	{
		result[*idx] = n + '0';
		++*idx;
		return ;
	}
	else
	{
		st_fillresult(n / 10, idx, result);
		st_fillresult(n % 10, idx, result);
	}
}

static int	st_numsize(long long n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		n *= -1;
		size = 1;
	}
	while (n > 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		idx;

	size = st_numsize((long long)n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	idx = 0;
	st_fillresult((long long)n, &idx, result);
	result[size] = '\0';
	return (result);
}
