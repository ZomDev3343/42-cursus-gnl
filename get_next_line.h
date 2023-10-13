/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:44:22 by truello           #+#    #+#             */
/*   Updated: 2023/10/13 16:03:48 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*data;
	ssize_t			read_size;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	*ft_calloc(size_t size, size_t len);
void	lst_push_back(t_list **head, t_list *elem);
void	lst_clear(t_list **head);

#endif
