/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/13 16:06:44 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size, size_t len)
{
	void	*res;
	size_t total;
	size_t	i;

	i = 0;
	total = size * len;
	res = malloc(total);
	while (i < total)
	{
		((unsigned char *) res)[i] = 0;
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
		cur = elem;
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
