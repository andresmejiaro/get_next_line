/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:51:41 by amejia            #+#    #+#             */
/*   Updated: 2023/01/27 16:52:22 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  (10)
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *s1, char *s2, size_t nb);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif