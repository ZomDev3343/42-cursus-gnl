/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:25:11 by truello           #+#    #+#             */
/*   Updated: 2023/10/12 17:15:08 by truello          ###   ########.fr       */
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
ssize_t	is_line(char *str);
char	*make_final_str(t_list *line);
ssize_t	get_final_len(t_list *line);
char	*get_reste_str(char *str);

t_list	*lstnew(void *data, ssize_t read_size);
void	lstadd_back(t_list *elem);
void	lstclear(t_list **lst);
char	*strdup(char *str, ssize_t len);

#endif
