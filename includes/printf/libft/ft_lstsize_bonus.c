/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartin- <gmartin-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:40:46 by gmartin-          #+#    #+#             */
/*   Updated: 2019/11/19 14:05:53 by gmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
		i++;
	}
	return (i);
}
