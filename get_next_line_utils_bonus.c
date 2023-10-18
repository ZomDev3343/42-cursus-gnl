/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/18 12:54:47 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Creates a new list element */
t_list	*lstnew(char *data, ssize_t read_size, int fd)
{
	t_list	*res;

	res = (t_list *) malloc(sizeof(t_list));
	if (!res || !data || read_size == 0)
		return (NULL);
	res->data = data;
	res->fd = fd;
	res->read_size = read_size;
	res->next = NULL;
	return (res);
}

/* Make a duplicate of a char buffer
	(not a well formed string)
*/
char	*strdupl(char *str, ssize_t read_size, ssize_t start)
{
	char	*res;
	ssize_t	i;

	i = start;
	if (!str || start < 0 || read_size <= 0 || start >= read_size)
		return (NULL);
	res = (char *) malloc(read_size - start);
	if (!res)
		return (NULL);
	while (i < read_size)
	{
		res[i - start] = (unsigned char) str[i];
		i++;
	}
	return (res);
}

/* Adds an element at the end of a list */
void	lst_push_back(t_list **head, t_list *elem)
{
	t_list	*cur;

	if (!elem)
		return ;
	elem->next = NULL;
	if (!*head)
	{
		*head = elem;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
}

/* Clears the list members with a particular fd property */
void	lst_clear_fd(t_list **head, int fd)
{
	t_list	*newlist;
	t_list	*cur;
	t_list	*tmp;

	newlist = NULL;
	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		if (cur->fd == fd)
		{
			free(cur->data);
			free(cur);
		}
		else
			lst_push_back(&newlist, cur);
		cur = tmp;
	}
	*head = newlist;
}

/* Get the last element of a list with a precise fd */
t_list	*flfd(t_list **head, int fd, char mode)
{
	t_list	*last;
	t_list	*cur;

	last = NULL;
	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (mode == 'f' || (mode == 'x'
					&& is_line(cur->data, cur->read_size) >= 0))
				return (cur);
			last = cur;
		}
		cur = cur->next;
	}
	if (mode == 'x')
		return (NULL);
	return (last);
}
