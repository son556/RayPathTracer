/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:56:20 by taehyeon          #+#    #+#             */
/*   Updated: 2023/03/15 15:53:30 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		++j;
	}
	result[i + j] = '\0';
	return (result);
}
