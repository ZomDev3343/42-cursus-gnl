/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:28:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/09 13:49:46 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*lstnew(void *data)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	elem->data = data;
	elem->next = 0;
	return (elem);
}
