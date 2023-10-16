/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:01 by truello           #+#    #+#             */
/*   Updated: 2023/10/16 13:43:13 by truello          ###   ########.fr       */
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

/* Main function to do the get_next_line */
char	*get_next_line(int fd)
{
	static t_list	*line;
	char			*readline;
	ssize_t			rs;

	if (fd == -1)
		return (NULL);
	readline = (char *) malloc(BUFFER_SIZE);
	rs = read(fd, readline, BUFFER_SIZE);
	while (rs > 0)
	{
		lst_push_back(&line, lstnew(strdupl(readline, rs), rs));
		if (is_line(readline, rs))
			break ;
		rs = read(fd, readline, BUFFER_SIZE);
	}
	free(readline);
	if (!line)
		return (NULL);
	print_list(line);
	lst_clear(&line);
	return (NULL);
}
