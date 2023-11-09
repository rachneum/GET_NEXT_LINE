/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:19 by rachou            #+#    #+#             */
/*   Updated: 2023/11/09 16:40:28 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
								   //count how many char are till '\n'.
	str_len = len_to_newline(list);//this is a function that takes a pointer to a list and is counting all the chars till the new line.
	next_str = malloc(str_len + 1);//so i know how much to malloc.  +1 for the '\0'.
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);//copy the string in the buffer ans return it.
	return (next_str);
}

void	append(t_list **list, char *buf)//list here is a pointer to a pointer.
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;//assign to list the value of new_node. so new_node is gonna become the first of new_node of the link list.
	else
		last_node->next = new_node;
	new_node->str_buf = buf;//assign to the new node string the buffer.
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{//necessary to place the \0 -> "string\0".
	int		char_read;
	char	*buf;
//scan line if '\n' present.	 //search inside the list if there is a new line. (and if there is not, get inside loop).
	while (!found_newline(*list))//searching for a new line char, bcs we have to fetch a string till the new line (new line included)
	{								  //+1: is for the \0 at the end.
		buf = malloc(BUFFER_SIZE + 1);//buf: is where i'm gonna stock my string.
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);//the read fct is gonna return me back the number of chars read
		if (!char_read)// if the number of chars read is 0.
		{
			free(buf);
			return ;//bcs it means that i have finished the file.
		}
		buf [char_read] = '\0';
		append(list, buff);//append: add.
	}
}

//it has to fetch a specific string from a specific file
char	*get_next_line(int fd)
{//static: variable that behaves like a global variable with local scope, only gnl can use this variable.
	static t_list	*list = NULL;
	char			*next_line;//i'll stock the next line i'm gonna take.
//fd are only positives.			read gives -1 if some problems on reading.
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);//create my list until i stumble into '\n'.

	if (list == NULL)
		return (NULL);
	next_line = get_line(list);//fetch the line from the list. i want to get the line that is stocked inside linklist and the heap.
	polish_list(&list);
	return (next_line);
}
