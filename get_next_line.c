/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2023/10/10 16:26:48 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Checks if a string contains '\n' */
ssize_t	is_line(char *str, ssize_t len)
{
	ssize_t	i;
	
	if (!str || len == 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/* Returns the next line from a file descriptor (NULL if no '\n' found and EOF) */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			read_size;
	char			*final_str;
	ssize_t			final_len;

	readline = (char *) malloc(BUFFER_SIZE);
	while (is_line(readline) == -1)
	{
		read_size = read(fd, readline, BUFFER_SIZE);
		if (read_size > 0)
			lstadd_back(&line, lstnew(strdup(readline, read_size), read_size));
	}
	if (!line)
		return (NULL);	
	
}
