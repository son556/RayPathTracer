/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:02:23 by taehyeon          #+#    #+#             */
/*   Updated: 2023/02/24 16:39:58 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	if (s == 0)
		return (0);
	while (i > 0)
	{
		--i;
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (0);
}
