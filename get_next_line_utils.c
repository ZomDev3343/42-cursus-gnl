/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/12 17:18:12 by truello          ###   ########.fr       */
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

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *lst;
	while (cur)
	{
		tmp = cur->next;
		free(tmp->data);
		free(tmp);
		cur = tmp;
	}
	*lst = 0;
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
