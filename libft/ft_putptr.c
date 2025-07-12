/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:56:14 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/05 11:25:46 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(uintptr_t ptr)
{
	char	*base;
	int		p;

	base = "0123456789abcdef";
	p = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (ptr >= 16)
		p = p + ft_putptr(ptr / 16);
	else
		p = ft_putstr("0x") + p;
	p = p + ft_putchar(base[ptr % 16]);
	return (p);
}
