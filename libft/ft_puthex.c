/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:55:58 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/05 11:25:26 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int nb, char format)
{
	int		r;
	char	*base;

	r = 0;
	if (format)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		r = r + ft_puthex(nb / 16, format);
	r = r + ft_putchar(base[nb % 16]);
	return (r);
}
