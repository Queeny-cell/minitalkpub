/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:03 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/05 11:25:33 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	r;

	r = 0;
	if (nb > 9)
	{
		r = r + ft_putnbr_unsigned(nb / 10);
		r = r + ft_putnbr_unsigned(nb % 10);
	}
	else
		r = r + ft_putchar('0' + nb);
	return (r);
}
