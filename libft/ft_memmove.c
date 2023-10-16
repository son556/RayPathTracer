/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:52:54 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/12 21:30:57 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
			++i;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			++i;
		}
	}
	return (dst);
}
