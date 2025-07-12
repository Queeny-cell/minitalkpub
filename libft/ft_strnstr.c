/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:06:36 by mapodevi          #+#    #+#             */
/*   Updated: 2025/05/05 10:24:19 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big2;

	i = 0;
	j = 0;
	big2 = (char *)big;
	if (little[0] == '\0' || little == big)
		return (big2);
	while (big2[i] && i < len)
	{
		while (big2[i + j] == little[j] && little[j] && big2[i + j]
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return (&big2[i]);
		i++;
		j = 0;
	}
	return (0);
}
