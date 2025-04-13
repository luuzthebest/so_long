/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:18:51 by hounajar          #+#    #+#             */
/*   Updated: 2024/11/20 01:19:15 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinedstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	joinedstr = malloc(len + 1);
	if (joinedstr == NULL)
		return (NULL);
	ft_strlcpy(joinedstr, s1, s1_len + 1);
	ft_strlcat(joinedstr, s2, len + 1);
	return (joinedstr);
}
