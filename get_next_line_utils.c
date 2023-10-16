/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/16 13:46:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Creates a new list element */
t_list	*lstnew(char *data, ssize_t read_size)
{
	t_list	*res;

	res = (t_list *) malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->data = data;
	res->read_size = read_size;
	return (res);
}

/* Make a duplicate of a char buffer
	(not a well formed string)
*/
char	*strdupl(char *str, ssize_t read_size)
{
	ssize_t	i;
	char	*res;

	res = (char *) malloc(read_size);
	i = 0;
	while (i < read_size)
	{
		res[i] = (unsigned char) str[i];
		i++;
	}
	return (res);
}

/* Adds an element at the end of a list */
void	lst_push_back(t_list **head, t_list *elem)
{
	t_list	*cur;

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

/* Clears a list */
void	lst_clear(t_list **head)
{
	t_list	*cur;
	t_list	*tmp;

	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->data);
		free(cur);
		cur = tmp;
	}
	*head = 0;
}
