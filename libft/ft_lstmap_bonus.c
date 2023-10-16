/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:56:04 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/13 18:11:33 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*list;
	t_list	*new;
	void	*newcontent;

	result = 0;
	list = lst;
	while (list)
	{
		newcontent = f(list->content);
		new = ft_lstnew(newcontent);
		if (!new || !newcontent)
		{
			del(newcontent);
			free(new);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, new);
		list = list->next;
	}
	return (result);
}
