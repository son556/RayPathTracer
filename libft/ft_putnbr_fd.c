/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:09:55 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/11 21:15:10 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	st_putnbr(long long n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		st_putnbr(-n, fd);
		return ;
	}
	if (n < 10)
	{
		n += '0';
		write(fd, &n, 1);
	}
	else
	{
		st_putnbr(n / 10, fd);
		st_putnbr(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	st_putnbr((long long)n, fd);
}
