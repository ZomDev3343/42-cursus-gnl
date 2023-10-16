/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/16 12:06:05 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	lst_push_back(t_list **head, t_list *elem)
{
	t_list	*cur;

	cur = *head;
	if (!cur)
	{
		*head = elem;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
}

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
