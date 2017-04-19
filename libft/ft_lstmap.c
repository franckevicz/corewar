/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:58:59 by mdubina           #+#    #+#             */
/*   Updated: 2016/12/02 12:26:03 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*resalt;

	resalt = NULL;
	if (lst == NULL)
		return (resalt);
	resalt = f(lst);
	lst = lst->next;
	resalt->next = ft_lstmap(lst, f);
	return (resalt);
}
