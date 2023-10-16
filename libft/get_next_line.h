/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:17:57 by taehyeon          #+#    #+#             */
/*   Updated: 2022/12/21 21:13:40 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_info
{
	int				cursor;
	int				size;
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_info	*next;
}	t_info;

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, const char *s2);
t_info	*ft_findinfo(t_info *head, int fd);
t_info	*ft_newinfo(void);
char	*ft_initresult(t_info *info);

#endif
