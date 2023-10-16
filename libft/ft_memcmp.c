/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:38:22 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/12 18:16:37 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			result = (int)((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (result);
		}
		++i;
	}
	return (result);
}
