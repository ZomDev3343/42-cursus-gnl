/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2023/10/13 15:23:55 by truello          ###   ########.fr       */
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
	while (i < len && str[i])
	{
		if (str[i] == '\n' || (unsigned char) str[i] == 0)
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
		if (is_line(cur->data, cur->read_size) == -1)
			len += cur->read_size;
		else
		{
			len += is_line(cur->data, cur->read_size);
			return (len);
		}
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
	res = (char *) ft_calloc(1, len + 1);
	if (!res || line->read_size == 0)
		return (NULL);
	while (line && i < len)
	{
		j = -1;
		while (++j < line->read_size)
		{
			res[i + j] = (line->data)[j];
			if (res[i + j] == '\n' || res[i + j] == '\0')
				return (res);
		}
		i += j;
		line = line->next;
	}
	free(res);
	return (NULL);
}

char	*get_reste_str(char *str, ssize_t *read_size)
{
	ssize_t	i;
	char	*res;
	ssize_t	reste_len;

	res = NULL;
	if (!str || !is_line(str, *read_size))
		return (res);
	i = 0;
	while (i < (*read_size) && str[i] != '\n')
		i++;
	reste_len = (*read_size) - i;
	if (reste_len > 0)
	{
		res = (char *) ft_calloc (1, *read_size - i + 1);
		if (!res)
			return (NULL);
		while (*read_size > i)
		{
			res[(*read_size) - i - 1] = str[(*read_size)];
			(*read_size)--;
		}
		*read_size = reste_len;
	}
	return (res);
}
/* Returns the next line from a file descriptor
(NULL if no '\n' found and EOF) */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			read_l;
	char			*final_str;
	char			*reste;

	readline = (char *) ft_calloc(1, BUFFER_SIZE + 1);
	while (read_l > 0 && is_line(readline, BUFFER_SIZE) == -1)
	{
		read_l = read(fd, readline, BUFFER_SIZE);
		if (read_l > 1)
		{
			lstadd_back(&line, lstnew(ft_strdup(readline, read_l), read_l));
			reste = get_reste_str(readline, &read_l);
		}
	}
	final_str = make_final_str(line);
	lstclear(&line);
	if (read_l > 1 && reste)
		lstadd_back(&line, lstnew(ft_strdup(reste, read_l), read_l));
	free(readline);
	free(reste);
	return (final_str);
}
