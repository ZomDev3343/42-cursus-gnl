/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/10 16:25:14 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Creates a new list element with a data and its size */
t_list	*lstnew(char *data, ssize_t read_size)
{
	t_list	*elem;

	if (!data)
		return (NULL);
	elem = (t_list *) malloc(sizeof(t_list));
	elem->data = data;
	elem->read_size = read_size;
	elem->next = 0;
	return (elem);
}

/* Adds an elements at the end of a list or set the list if empty */
void	lstadd_back(t_list **head, t_list *elem)
{
	t_list	*cur;

	if (!head)
		return ;
	cur = *head;
	if (!*head)
	{
		*head = elem;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
}

/* Construct a string from memory space and replace 'EOF' by '\0' for correct string */
char	*makestr(void *data, size_t size)
{
	char	*res;
	size_t	i;
	unsigned char	has_eof;

	i = 0;
	has_eof = (((char *)data)[size] == (char)-1);
	res = (char *) malloc(size + !has_eof);
	res[size] = 0;
	while (i < size - has_eof)
	{
		res[i] = ((unsigned char *) data)[i];
		i++;
	}
	return (res);
}

/* Make a copy of str which is 'len' characters long */
char	*strdup(char *str, ssize_t len)
{
	char	*res;

	res = (char *) malloc(len + 1);
	res[len] = 0;
	while (--len >= 0)
		res[len] = ((unsigned char *) str)[len];
	return (res);
}
