/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:08:23 by mapodevi          #+#    #+#             */
/*   Updated: 2025/07/21 18:31:32 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_init_msg(t_static *data, pid_t pid)
{
	if (data->len <= 0 || data->len > 1000000)
	{
		ft_printf("Invalid len: %d\n", data->len);
		kill(pid, SIGUSR2);
		exit(1);
	}
	data->msg = malloc(data->len + 1);
	if (!data->msg)
	{
		ft_printf("Malloc failed\n");
		exit(1);
	}
	data->msg[data->len] = '\0';
}

static void	ft_handle_len(t_static *data, pid_t pid)
{
	data->len |= (data->byte << (data->received * 8));
	if (++data->received == 4)
	{
		ft_init_msg(data, pid);
		data->state = 1;
		data->received = 0;
	}
}

static void	ft_handle_msg(t_static *data, pid_t pid)
{
	data->msg[data->received++] = data->byte;
	if (data->received == data->len)
	{
		write(1, data->msg, data->len);
		kill(pid, SIGUSR2);
		free(data->msg);
		data->msg = NULL;
		data->len = 0;
		data->state = 0;
		data->received = 0;
	}
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static t_static	data;

	(void)context;
	if (signal == SIGUSR1)
		data.byte |= (1 << data.bit);
	else if (signal == SIGUSR2)
		data.byte &= ~(1 << data.bit);
	if (++data.bit == 8)
	{
		if (data.state == 0)
			ft_handle_len(&data, info->si_pid);
		else
			ft_handle_msg(&data, info->si_pid);
		data.bit = 0;
		data.byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	ft_printf("Waiting for a message...\n");
	sig.sa_sigaction = ft_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause ();
	}
	return (0);
}
