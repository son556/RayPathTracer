/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:22:32 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/11 19:01:26 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1);
	i = 0;
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = s1[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
