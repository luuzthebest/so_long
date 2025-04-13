/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:17:45 by hounajar          #+#    #+#             */
/*   Updated: 2024/11/26 11:26:19 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	isdigit;
	int	isalpha;

	isalpha = ft_isalpha(c);
	isdigit = ft_isdigit(c);
	if (isalpha == 1 || isdigit == 1)
	{
		return (1);
	}
	return (0);
}
