/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:07:23 by taehyeon          #+#    #+#             */
/*   Updated: 2023/03/16 15:55:43 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;
	size_t	len;

	if (size == 0 || count == 0)
	{
		result = malloc(0);
		if (!result)
			return (0);
		return (result);
	}
	result = malloc(size * count);
	if (!result)
		return (0);
	i = 0;
	len = count * size;
	while (i < len)
	{
		((unsigned char *)result)[i] = 0;
		++i;
	}
	return (result);
}
