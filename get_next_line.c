/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2023/10/12 17:20:42 by truello          ###   ########.fr       */
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

ssize_t	get_final_len(t_list *line)
{
	t_list	*cur;
	ssize_t	len;

	len = 0;
	cur = line;
	while (cur)
	{
		len += cur->read_size;
		cur = cur->next;
	}
	return (len);
}

char	*make_final_str(t_list *line)
{
	ssize_t	len;
	char	*res;
	ssize_t	i;
	ssize_t	j;

	len = get_final_len(line);
	i = 0;
	res = (char *) malloc (len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (line && i < len)
	{
		j = 0;
		while (j < line->read_size)
		{
			res[i + j] = (line->data)[j];
			j++;
		}
		i += j;
		line = line->next;
	}
	return (res);
}

char	*get_reste_str(char *str, ssize_t read_size)
{
	ssize_t	i;
	char	*res;

	res = NULL;
	if (!str || !is_line(str))
		return (res);
	i = 0;
	while (i < read_size && str[i] != '\n')
		i++;
	if (read_size - i + 1 > 0)
	{
		res = (char *) malloc (read_size - i + 1);
		if (!res)
			return (NULL);
		while (--read_size >= i)
			res[read_size - i] = str[read_size];
	}
	return (res);
}

/* Returns the next line from a file descriptor
(NULL if no '\n' found and EOF) */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			read_size;
	char			*final_str;
	char			*reste;

	readline = (char *) malloc(BUFFER_SIZE);
	while (is_line(readline) == -1)
	{
		read_size = read(fd, readline, BUFFER_SIZE);
		if (read_size > 0)
		{
			lstadd_back(&line, lstnew(strdup(readline, read_size), read_size));
			reste = get_reste_str(readline, read_size);
		}
	}
	if (!line)
		return (NULL);
	final_str = make_final_str(line);
	lstclear(&line);
	lstadd_back(line, lstnew(strdup(reste, read_size)));
	free(readline);
	free(reste);
	return (final_str);
}
