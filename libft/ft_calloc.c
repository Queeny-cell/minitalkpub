/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:34:55 by mapodevi          #+#    #+#             */
/*   Updated: 2025/04/29 16:22:21 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_memset(s, 0, (nmemb * size));
	return (s);
}
