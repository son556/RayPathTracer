/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:17:54 by taehyeon          #+#    #+#             */
/*   Updated: 2022/12/21 21:20:53 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static char	*st_error(char *result, t_info *head, int fd)
{
	t_info	*prev;
	t_info	*next;

	prev = head;
	next = head->next;
	while (next)
	{
		if (next->fd == fd)
		{
			prev->next = next->next;
			free(next);
			break ;
		}
		prev = next;
		next = next->next;
	}
	if (result != 0)
		free(result);
	result = 0;
	return (result);
}

static char	*st_return(char *result, t_info *head, int fd)
{
	t_info	*prev;
	t_info	*next;

	prev = head;
	next = head->next;
	while (next)
	{
		if (next->fd == fd)
		{
			prev->next = next->next;
			free(next);
			break ;
		}
		prev = next;
		next = next->next;
	}
	return (result);
}

static void	st_initbuf(t_info *info)
{
	size_t	i;

	i = info->size;
	info->buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static t_info	head;
	char			*result;
	t_info			*info;

	info = ft_findinfo(&head, fd);
	if (info == 0)
		return (0);
	result = ft_initresult(info);
	if (fd < 0 || read(fd, info->buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (st_error(result, &head, fd));
	if (gnl_strlen(result) > 0 && result[gnl_strlen(result) - 1] == '\n')
		return (result);
	while (info->size == BUFFER_SIZE)
	{
		info->size = read(fd, info->buffer, BUFFER_SIZE);
		if (info->size <= 0)
			return (st_return(result, &head, fd));
		info->cursor = 0;
		st_initbuf(info);
		result = gnl_strjoin(result, info->buffer + info->cursor);
		info->cursor += gnl_strlen(info->buffer + info->cursor);
		if (result[gnl_strlen(result) - 1] == '\n')
			return (result);
	}
	return (st_return(result, &head, fd));
}
