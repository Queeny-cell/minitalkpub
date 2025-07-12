/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:17:18 by mapodevi          #+#    #+#             */
/*   Updated: 2025/05/05 12:03:41 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*write_dst(char *dst, int count, int i, long int nb)
{
	while (count > i && count--)
	{
		dst[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			count;
	int			i;
	char		*dst;

	nb = n;
	count = count_size(nb);
	i = 0;
	if (nb < 0 || count == 0)
		count++;
	dst = malloc((count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		dst[0] = '-';
		i++;
	}
	dst[count] = '\0';
	return (write_dst(dst, count, i, nb));
}
