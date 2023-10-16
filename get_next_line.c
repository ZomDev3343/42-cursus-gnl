/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2023/10/16 14:42:17 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Returns the index of the first newline character if found
	in the string, else returns 0
*/
static unsigned char	is_line(char *str, ssize_t read_size)
{
	ssize_t	i;

	i = 0;
	while (i < read_size)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static ssize_t	get_line_length(t_list *line)
{
	ssize_t	len;
	ssize_t	newline_idx;

	len = 0;
	while (line)
	{
		newline_idx = is_line(line->data, line->read_size); 
		if (newline_idx)
			len += newline_idx + 1;
		else
			len += line->read_size;
		line = line->next;
	}
	return (len);
}

/* Fill the buffer with all the characters to form the line string*/
void	make_line(t_list *lst, char *buf, ssize_t len)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < lst->read_size && i + j < len)
		{
			buf[i + j] = (lst->data)[j];
			j++;
		}
		i += j;
	}
}

/* Returns the well-formed read line and
	creates the remaining string node
*/
static char	*process_list(t_list **lst)
{
	char	*res;
	ssize_t	line_len;

	line_len = get_line_length(*lst);
	res = (char *) malloc(line_len + 1);
	res[line_len] = '\0';
	make_line(*lst, res, line_len);
	return (res);
}

/* Main function to do the get_next_line */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			rs;
	char			*res;

	if (fd == -1)
		return (NULL);
	readline = (char *) malloc(BUFFER_SIZE);
	rs = read(fd, readline, BUFFER_SIZE);
	while (rs > 0)
	{
		lst_push_back(&line, lstnew(strdupl(readline, rs, 0), rs));
		if (is_line(readline, rs))
			break ;
		rs = read(fd, readline, BUFFER_SIZE);
	}
	free(readline);
	if (!line)
		return (NULL);
	//print_list(line);
	res = process_list(&line);
	lst_clear(&line);
	return (res);
}
