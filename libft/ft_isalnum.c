/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:52:22 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/10 14:43:39 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c < '0' || c > 'z')
		return (0);
	else if (c > '9' && c < 'A')
		return (0);
	else if (c > 'Z' && c < 'a')
		return (0);
	else
		return (c);
}
