/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:11:57 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/12 17:49:47 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	st_findset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static size_t	st_leftcount(const char *s1, const char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (st_findset(s1[i], set))
			count += 1;
		else
			break ;
		++i;
	}
	return (count);
}

static size_t	st_rightcount(const char *s1, const char *set)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(s1);
	count = 0;
	if (i == 0)
		return (count);
	while (--i > 0)
	{
		if (st_findset(s1[i], set))
			count += 1;
		else
			break ;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	size_t	i;
	size_t	left;
	size_t	right;
	char	*result;

	left = st_leftcount(s1, set);
	right = st_rightcount(s1, set);
	if (left == ft_strlen(s1))
		size = 0;
	else
		size = ft_strlen(s1) - left - right;
	i = 0;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = s1[left + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
