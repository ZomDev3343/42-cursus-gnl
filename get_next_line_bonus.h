/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:44:22 by truello           #+#    #+#             */
/*   Updated: 2023/10/17 19:03:31 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*data;
	ssize_t			read_size;
	int				fd;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

void	lst_push_back(t_list **head, t_list *elem);
t_list	*flfd(t_list *head, int fd, char mode);
void	lst_clear_fd(t_list **head, int fd);
t_list	*lstnew(char *data, ssize_t read_size, int fd);
char	*strdupl(char *str, ssize_t read_size,
			ssize_t start);

/* Test Functions */
void	print_list(t_list *head);

#endif
