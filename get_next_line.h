/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:25:11 by truello           #+#    #+#             */
/*   Updated: 2023/10/13 15:05:18 by truello          ###   ########.fr       */
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
ssize_t	is_line(char *str, ssize_t len);
char	*make_final_str(t_list *line);
ssize_t	get_final_len(t_list *line);
char	*get_reste_str(char *str, ssize_t *read_size);

t_list	*lstnew(char *data, ssize_t read_size);
void	lstadd_back(t_list **head, t_list *elem);
void	lstclear(t_list **lst);
char	*ft_strdup(char *str, ssize_t len);
void	*ft_calloc(size_t size, size_t len);

#endif
