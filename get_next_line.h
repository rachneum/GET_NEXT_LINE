/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:04:51 by rachou            #+#    #+#             */
/*   Updated: 2023/11/16 13:36:20 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*get_line(t_list *list);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buf);
void	copy_str(t_list *list, char *str);
void	polish_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
int		len_to_newline(t_list *list);
int		found_newline(t_list *list);
t_list	*find_last_node(t_list	*list);
#endif