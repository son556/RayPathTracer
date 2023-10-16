/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:56:50 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/12 21:40:09 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	st_findstr(const char *s, const char *find, int idx, size_t len)
{
	size_t	i;

	i = 0;
	while (find[i])
	{
		if (s[idx + i] != find[i])
			return (0);
		++i;
	}
	if (i + idx > len)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (st_findstr(haystack, needle, i, len) == 1)
				return ((char *)haystack + i);
		}
		++i;
	}
	return (0);
}
