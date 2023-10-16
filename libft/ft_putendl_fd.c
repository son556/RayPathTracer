/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:07:03 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/12 19:01:37 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
	write(fd, "\n", 1);
}
