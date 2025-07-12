/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:09 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/05 11:25:39 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	r;

	r = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		r = r + ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		r = r + ft_putnbr(nb / 10);
		r = r + ft_putnbr(nb % 10);
	}
	else
		r = r + ft_putchar('0' + nb);
	return (r);
}
