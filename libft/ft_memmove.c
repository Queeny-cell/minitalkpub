/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:02:25 by mapodevi          #+#    #+#             */
/*   Updated: 2025/04/29 17:47:55 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dlen;
	char	*slen;

	dlen = (char *)dest;
	slen = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (slen < dlen)
	{
		while (n > 0)
		{
			n--;
			dlen[n] = slen[n];
		}
	}
	else
	{
		ft_memcpy(dlen, slen, n);
	}
	return (dest);
}
