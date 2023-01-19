/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:14:22 by amejia            #+#    #+#             */
/*   Updated: 2023/01/19 22:41:37 by amejia           ###   ########.fr       */
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

void self_reference_free(char **target, char *other,char *(*f)(const char *,const char *))
{
	char	*temp1;
	
	temp1 = (*f)(*target,other);
	free(*target);
	*target = temp1;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	int 	counter;

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