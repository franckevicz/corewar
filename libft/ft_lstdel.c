/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:02:44 by mdubina           #+#    #+#             */
/*   Updated: 2016/11/30 17:41:51 by mdubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (*alst != NULL)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		ft_lstdel((&(*alst)), del);
	}
}
