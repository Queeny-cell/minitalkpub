/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:32:34 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/18 20:42:44 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct s_static
{
	int		bit;
	int		byte;
	int		state;
	int		len;
	int		received;
	char	*msg;
}	t_static;

#endif