/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:39:27 by taehyeon          #+#    #+#             */
/*   Updated: 2023/03/16 19:23:07 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	i = 1;
	next = lst->next;
	while (next)
	{
		next = next->next;
		++i;
	}
	return (i);
}
