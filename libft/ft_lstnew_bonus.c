/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapodevi <mapodevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:38:34 by mapodevi          #+#    #+#             */
/*   Updated: 2025/05/05 12:29:10 by mapodevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nelt;

	nelt = malloc(sizeof(t_list));
	if (!nelt)
		return (NULL);
	nelt->content = content;
	nelt->next = NULL;
	return (nelt);
}
