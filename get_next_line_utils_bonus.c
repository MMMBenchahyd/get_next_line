/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:38:34 by mbenchah          #+#    #+#             */
/*   Updated: 2024/11/21 00:57:52 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_clear(char **p, char *ptr)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
	if (ptr)
		free(ptr);
	return (NULL);
}

char	ft_strchr(char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (c);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, char c)
{
	char	*p;
	size_t	i;
	size_t	slen1;
	size_t	slen2;

	i = 0;
	slen1 = ft_strlen(s1, c);
	slen2 = ft_strlen(s2, c);
	if (!slen1 && !slen2)
		return (NULL);
	p = (char *)malloc(slen2 + slen1 + 1);
	if (!p)
		return (NULL);
	while (s1 != NULL && i < slen1 && *s1)
		p[i++] = *s1++;
	while (s2 != NULL && i < slen2 + slen1 && *s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	if (!s)
		return (0);
	while (s[cnt] && s[cnt] != c)
		cnt++;
	if (s[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*ft_substr(char *s, int i_str, char c)
{
	size_t	slen;
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (i_str && *s)
	{
		if (*s++ == '\n')
			break ;
	}
	slen = ft_strlen(s, c);
	ptr = (char *)malloc(slen + 1);
	if (!ptr || !slen)
		return (ft_clear(0, ptr));
	while (i < slen)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[slen] = '\0';
	return (ptr);
}
