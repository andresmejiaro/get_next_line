/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:26:08 by amejia            #+#    #+#             */
/*   Updated: 2023/01/22 15:48:56 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	counter;

	mem = malloc(count * size);
	if (mem == 0)
		return (0);
	counter = 0;
	while (counter < count * size)
	{
		*((char *)(mem + counter)) = '\0';
		counter++;
	}
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*to_return;

	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	to_return = (char *)malloc((len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	if (len == 0)
		ft_strlcpy(to_return, "", 1);
	else
		ft_strlcpy(to_return, (char *)(s + start), len + 1);
	return (to_return);
}

char	*create_line_from_left(char **left)
{
	char	*breakpoint;
	char	*before;
	char	*after;
	char	*old;

	breakpoint = ft_strchr(*left, '\n');
	if (breakpoint == 0)
		return (*left);
	before = ft_substr(*left, 0, (int)(breakpoint - *left + 1));
	after = ft_substr(breakpoint + 1, 0, ft_strlen(breakpoint + 1));
	old = *left;
	*left = after;
	free(old);
	return (before);
}

char	*read_from_file(int fd, char **left)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*old;
	int		k;
	int		bytes_read;

	k = -1;
	while (k++ < BUFFER_SIZE)
		buffer[k] = '\0';
	if (*left == 0)
		*left = ft_calloc(1, 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		old = *left;
		*left = ft_strjoin(*left, buffer);
		return (free(old), get_next_line(fd));
	}
	else if (bytes_read == -1 || !(ft_strlen(*left)))
	{
		free(*left);
		return (*left = 0, (char *)0);
	}
	old = ft_substr(*left, 0, ft_strlen(*left));
	free (*left);
	return (*left = 0, old);
}

char	*get_next_line(int fd)
{
	static char	*left[1024];

	if (fd < 0 || fd > 1023)
		return (0);
	if (left[fd] != 0 && ft_strchr(left[fd], '\n'))
		return (create_line_from_left(&left[fd]));
	else
		return (read_from_file(fd, &left[fd]));
}
