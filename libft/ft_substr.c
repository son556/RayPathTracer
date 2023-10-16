/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:41:53 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/13 18:32:49 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	st_min(size_t	a, size_t	b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	slen;
	size_t	size;

	i = 0;
	slen = ft_strlen(s);
	start = st_min(start, slen);
	size = st_min(slen - start, len);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	while (i < len && start + i < slen && s[start + i])
	{
		result[i] = s[start + i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
