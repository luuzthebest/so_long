/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:44:41 by hounajar          #+#    #+#             */
/*   Updated: 2024/11/19 01:11:10 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
// int main() {
//     // Test case 1: Basic memory move with non-overlapping memory
//     char str1[] = "Hello, World!";
//     ft_memmove(str1 + 7, str1, 5);
//     printf("After ft_memmove: %s\n", str1);  // Expected: "Hello, Hello!"

//     // Test case 2: Memory move with overlapping memory (src < dest)
//     char str2[] = "ABCDEFGH";
//     ft_memmove(str2 + 3, str2, 4);
//     printf("After ft_memmove: %s\n", str2);  // Expected: "ABCABC"

//     // Test case 3: Memory move with no overlap (src == dest)
//     char str3[] = "TestNoMove";
//     ft_memmove(str3, str3 + 4, 4);
//     printf("After ft_memmove: %s\n", str3);  // Expected: "NoMove"

//     // Test case 4: Zero bytes to move
//     char str4[] = "NoChange";
//     ft_memmove(str4, str4 + 3, 0);
//     printf("After ft_memmove: %s\n", str4);  // Expected: "NoChange"

//     return 0;
// }
// int main(){
// 	char *s = "hello world";
// 	ft_memmove(s, s+6, 5);
// }
// hello every world
// every to hello | str+7 src str dest
// overlappingoverlapping
// vlappng of overlapping
// memset can be very veryveryveryl......
// memset can be very very ul 
