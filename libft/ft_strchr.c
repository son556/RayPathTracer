/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:48 by taehyeon          #+#    #+#             */
/*   Updated: 2023/02/24 15:20:27 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		++i;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	else
		return (0);
}
