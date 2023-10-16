/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:02:56 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/11 19:01:26 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	result;
	size_t	len;
	size_t	initlen;

	result = ft_strlen(src) + dstsize;
	initlen = ft_strlen(dst);
	if (dstsize == 0 || dstsize - 1 < initlen)
		return (result);
	i = 0;
	len = ft_strlen(dst);
	while (i < dstsize - 1 - initlen)
	{
		if (src[i] == '\0')
			break ;
		dst[len] = src[i];
		++i;
		++len;
	}
	dst[len] = '\0';
	result = ft_strlen(src) + initlen;
	return (result);
}
