/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneuman <raneuman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:33 by raneuman          #+#    #+#             */
/*   Updated: 2024/02/05 14:10:59 by raneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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