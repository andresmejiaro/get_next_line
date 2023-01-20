/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:18 by amejia            #+#    #+#             */
/*   Updated: 2023/01/20 17:53:27 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *initialize_get_next_line(int *n_char_read, char **buffer, char **lvr, int fd)
{
	if (fd <0 || fd > 1023 || read(fd,0,0) == -1)
		return (0);
	if (*lvr == 0)
	{
		*lvr =(char *) ft_calloc(1,1);
		*n_char_read = BUFFER_SIZE;
	}
	if (ft_strlen(*lvr) == 0 && *n_char_read < BUFFER_SIZE)
		return 0;
	*buffer =(char *) ft_calloc(BUFFER_SIZE+1,1);
	return ((char *) ft_calloc(1,1));   
}


// lines descr
// 0 Buffer 1 line 2 position 3 temp

char *get_next_line(int fd)
{
	char *st[4];
	static char *lvr;
	static int n_char_read;
	static int n_read;
	 
	if (!(st[1] = initialize_get_next_line(&n_char_read, &st[0], &lvr, fd)))
		return 0;
	while (!(st[2]=ft_strchr(lvr,'\n')))
	{
	   if(n_char_read < BUFFER_SIZE)
		{
			if(n_read == 1 && n_char_read == 0)
				return (0);
			self_reference_free(&st[1],lvr,ft_strjoin);
			ft_strlcpy(lvr,"",1);
			return(free(st[0]),st[1]);
		} 
		else if((n_char_read = read(fd,st[0],BUFFER_SIZE)))
		{
			
			self_reference_free(&lvr,st[0],ft_strjoin);
		}
		else
			n_read++;
	}
	st[3] = ft_substr(lvr,0,(int)(st[2] - lvr+1));
	self_reference_free(&st[1],st[3],ft_strjoin);
	free(st[3]);
	st[3] = ft_substr(st[2]+1,0,ft_strlen(st[2]+1));
	free(lvr);
	lvr = st[3];
	return(free(st[0]),st[1]);
}
