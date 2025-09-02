/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:37:03 by mbenchah          #+#    #+#             */
/*   Updated: 2024/11/21 00:57:52 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2, char c);
size_t	ft_strlen(char *s, char c);
char	*ft_substr(char *s, int i_str, char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_clear(char **p, char *ptr);

#endif