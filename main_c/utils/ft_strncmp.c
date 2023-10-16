/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:29:41 by chanson           #+#    #+#             */
/*   Updated: 2023/05/31 18:30:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			result = (int)(unsigned char)s1[i] - (int)(unsigned char)s2[i];
			return (result);
		}
		++i;
	}
	return (result);
}
