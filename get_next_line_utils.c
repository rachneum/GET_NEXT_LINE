/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rachou <rachou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:09:59 by rachou            #+#    #+#             */
/*   Updated: 2023/11/09 16:41:08 by rachou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)//== list != NULL.
	{
		i = 0;					//== (list->str_buf[i] != 0).
		while (list->str_buf[i])//the char inside the string of the node is different from 0.
		{
			if (list->str_buf[i] == '\n')//check if the char is the newline.
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;//this is gonna lead me to the final node that is pointing to NULL.
	}
	return (len);
}
void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])//until i have a char wich is different from 0.
		{
			if (list->str_buf[i] == '\n')//check if the char pointed by i is equal to '\n'.
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buf[i++];//just copy the string.
		}
		list = list->next;//go to the next node.
	}
	str[k] = '\0';
}