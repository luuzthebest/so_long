/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:35:37 by hounajar          #+#    #+#             */
/*   Updated: 2024/11/26 04:40:09 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	len_check;

	if (!s)
		return (NULL);
	slen = strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	len_check = slen - start;
	if (len_check > len)
		len_check = len;
	substr = malloc(len_check + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len_check + 1);
	return (substr);
}
