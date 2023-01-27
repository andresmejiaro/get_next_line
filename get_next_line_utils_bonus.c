/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:14:22 by amejia            #+#    #+#             */
/*   Updated: 2023/01/22 15:10:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;

	to_return = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (to_return == 0)
		return (0);
	ft_strlcpy(to_return, (char *)s1, -1);
	ft_strlcat(to_return, (char *)s2, -1);
	return (to_return);
}

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (dstsize < len_dest)
		return (len_src + dstsize);
	while (*dest != '\0' )
		dest++;
	ft_strlcpy(dest, src, dstsize - len_dest);
	return (len_src + len_dest);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	size_src;

	size_src = ft_strlen(src);
	counter = 0;
	while (counter < size && counter <= size_src)
	{
		if (counter < size - 1 && counter < size_src)
			*dest = *src;
		else
			*dest = '\0';
		if (counter < size - 1)
			dest++;
		if (counter < size_src - 1)
			src++;
		counter++;
	}
	return (size_src);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
