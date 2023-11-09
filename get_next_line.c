/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:19 by rachou            #+#    #+#             */
/*   Updated: 2023/11/09 15:08:04 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
