/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeon <taehyeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:03:22 by taehyeon          #+#    #+#             */
/*   Updated: 2022/11/13 21:43:45 by taehyeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	st_wordlen(const char *s, char c, unsigned int idx)
{
	size_t	len;

	len = 0;
	while (s[idx + len] && s[idx + len] != c)
		++len;
	return (len);
}

static size_t	st_wordcount(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		flag;

	count = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag && s[i] != c)
		{
			flag = 0;
			++count;
		}
		++i;
	}
	return (count);
}

static char	**st_freeword(char **result, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(result[i]);
		++i;
	}
	free(result);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char			**result;
	size_t			idx;
	size_t			cnt;

	idx = 0;
	cnt = 0;
	result = (char **)malloc(sizeof(char *) * (st_wordcount(s, c) + 1));
	if (!result)
		return (0);
	while (s[idx])
	{
		if (st_wordlen(s, c, idx) == 0)
		{
			++idx;
			continue ;
		}
		result[cnt] = ft_substr(s, idx, st_wordlen(s, c, idx));
		if (!result[cnt])
			return (st_freeword(result, cnt));
		idx += st_wordlen(s, c, idx);
		++cnt;
	}
	result[cnt] = 0;
	return (result);
}
