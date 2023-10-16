/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:17:59 by taehyeon          #+#    #+#             */
/*   Updated: 2022/12/21 21:57:24 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_initresult(t_info *info)
{
	char	*result;

	result = 0;
	if (info->cursor != 0 && info->cursor != info->size)
	{
		result = gnl_strjoin(result, info->buffer + info->cursor);
		info->cursor += gnl_strlen(info->buffer + info->cursor);
		if (info->cursor > info->size)
			info->cursor = info->size;
	}
	if (result == 0)
		info->size = BUFFER_SIZE;
	return (result);
}

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
		{
			++len;
			return (len);
		}
		++len;
	}
	return (len);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*result;
	int		size1;
	int		size2;
	int		i;

	size1 = gnl_strlen(s1);
	size2 = gnl_strlen(s2);
	i = -1;
	if (size1 + size2 == 0)
		return (0);
	result = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!result)
		return (0);
	while (++i < size1)
		result[i] = s1[i];
	i = -1;
	while (++i < size2)
		result[size1 + i] = s2[i];
	result[size1 + size2] = '\0';
	if (s1)
		free(s1);
	return (result);
}

t_info	*ft_newinfo(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->cursor = 0;
	info->size = BUFFER_SIZE;
	info->fd = -1;
	info->next = 0;
	return (info);
}

t_info	*ft_findinfo(t_info *head, int fd)
{
	t_info	*info;
	t_info	*prev;

	info = head->next;
	prev = head;
	while (info)
	{
		prev = info;
		if (info->fd == fd)
			return (info);
		info = info->next;
	}
	info = ft_newinfo();
	if (info == 0)
		return (0);
	info->fd = fd;
	prev->next = info;
	return (info);
}
