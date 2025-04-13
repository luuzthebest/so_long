/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:43:03 by hounajar          #+#    #+#             */
/*   Updated: 2025/03/18 00:34:11 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	t_stack	*nxt;

	if (!lst || !f)
		return ;
	nxt = lst;
	while (nxt != NULL)
	{
		f(nxt->content);
		nxt = nxt->next;
	}
}
