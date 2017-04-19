/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:49:48 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/30 19:13:14 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	if ((element = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!(content))
	{
		element->content = NULL;
		element->content_size = 0;
		element->next = NULL;
		return (element);
	}
	if (!(element->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(element->content, content, content_size);
	element->content_size = content_size;
	element->next = NULL;
	return (element);
}
