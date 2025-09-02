/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:36:28 by mbenchah          #+#    #+#             */
/*   Updated: 2024/11/23 11:58:19 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = b;
	i = 0;
	while (i < len)
		p[i++] = (unsigned char ) c;
	return (b);
}

char	*make_line(char *ptr, char **static_ptr)
{
	char	*tmp;

	tmp = ptr;
	ptr = ft_strjoin(*static_ptr, ptr, '\n');
	if (!ptr)
		return (ft_clear(static_ptr, tmp));
	if (ft_strchr(*static_ptr, '\n'))
		tmp = *static_ptr;
	else
		ft_clear(static_ptr, 0);
	*static_ptr = ft_substr(tmp, 1, 0);
	if (!*static_ptr && ft_strlen(tmp, 0) != ft_strlen(tmp, '\n'))
		return (ft_clear(&tmp, ptr));
	ft_clear(&tmp, 0);
	return (ptr);
}

char	*read_line(char *buff, int fd, char **static_ptr)
{
	char	*tmp;
	char	*ptr;
	size_t	i;

	tmp = NULL;
	ptr = NULL;
	while (!ft_strchr(buff, '\n'))
	{
		tmp = ptr;
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buff[i] = 0;
		ptr = ft_strjoin(ptr, buff, 0);
		ft_clear(0, tmp);
		if (!ptr)
			return (ft_clear(static_ptr, 0));
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*static_ptr[OPEN_MAX];
	char		*buff;
	char		*ptr;

	ptr = NULL;
	if (fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647
		|| read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= OPEN_MAX)
			ft_clear(&static_ptr[fd], 0);
		return (NULL);
	}
	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(static_ptr[fd]), static_ptr[fd] = NULL, NULL);
	ft_memset(buff, 0, (size_t)BUFFER_SIZE + 1);
	if (!ft_strchr(static_ptr[fd], '\n'))
	{
		ptr = read_line(buff, fd, &static_ptr[fd]);
		if (!ptr && !static_ptr[fd])
			return (ft_clear(&buff, 0));
	}
	free(buff);
	ptr = make_line(ptr, &static_ptr[fd]);
	return (ptr);
}
