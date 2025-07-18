/* void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;

	static int		bit = 0;
	static int		byte = 0;
	static int		state = 0;
	static int		len = 0;
	static char		*msg = NULL;
	static int		received_chars = 0;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	else if (signal == SIGUSR2)
		byte &= ~(1 << bit);
	bit++;

	if (bit == 8)
	{
		if (state == 0)
		{
			len |= (byte << (received_chars * 8));
			received_chars++;
			if (received_chars == 4)
			{
				if (len <= 0 || len > 1000000)
				{
					ft_printf("Invalid len: %d\n", len);
					exit(1);
				}
				msg = malloc(len + 1);
				if (!msg)
				{
					ft_printf("Malloc failed\n");
					exit(1);
				}
				msg[len] = '\0';
				state = 1;
				received_chars = 0;
			}
		}
		else if (state == 1)
		{
			msg[received_chars++] = byte;
			if (received_chars == len)
			{
				// ft_printf("%s\n", msg);
				write(1, msg, len);
				kill(info->si_pid, SIGUSR2);
				free(msg);
				msg = NULL;
				len = 0;
				state = 0;
				received_chars = 0;
			}
		}
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
} */

/* void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;

	static int		bit = 0;
	static int		byte = 0;
	static int		state = 0;
	static int		len = 0;
	static char		*msg = NULL;
	static int		received_chars = 0;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	else if (signal == SIGUSR2)
		byte &= ~(1 << bit);
	bit++;

	if (bit == 8)
	{
		if (state == 0)
		{
			len |= (byte << (received_chars * 8));
			received_chars++;
			if (received_chars == 4)
			{
				if (len <= 0 || len > 1000000)
				{
					ft_printf("Invalid len: %d\n", len);
					exit(1);
				}
				msg = malloc(len + 1);
				if (!msg)
				{
					ft_printf("Malloc failed\n");
					exit(1);
				}
				msg[len] = '\0';
				state = 1;
				received_chars = 0;
			}
		}
		else if (state == 1)
		{
			msg[received_chars++] = byte;
			if (received_chars == len)
			{
				// ft_printf("%s\n", msg);
				write(1, msg, len);
				kill(info->si_pid, SIGUSR2);
				free(msg);
				msg = NULL;
				len = 0;
				state = 0;
				received_chars = 0;
			}
		}
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
} */
/*static void	ft_init_msg(int *len, char **msg)
{
	if (*len <= 0 || *len > 1000000)
	{
		ft_printf("Invalid len: %d\n", *len);
		exit(1);
	}
	*msg = malloc(*len + 1);
	if (!*msg)
	{
		ft_printf("Malloc failed\n");
		exit(1);
	}
	(*msg)[*len] = '\0';
}

static void	ft_handle_len(int *len, int *byte, int *received, int *state, char **msg)
{
	*len |= (*byte << (*received * 8));
	if (++(*received) == 4)
	{
		ft_init_msg(len, msg);
		*state = 1;
		*received = 0;
	}
}

static void	ft_handle_msg(int *len, int *received, int *state, char **msg, int byte, pid_t pid)
{
	(*msg)[(*received)++] = byte;
	if (*received == *len)
	{
		write(1, *msg, *len);
		kill(pid, SIGUSR2);
		free(*msg);
		*msg = NULL;
		*len = 0;
		*state = 0;
		*received = 0;
	}
}

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	byte;
	static int	state;
	static int	len;
	static int	received;
	static char	*msg;

	(void)context;
	if (signal == SIGUSR1)
		byte |= (1 << bit);
	else if (signal == SIGUSR2)
		byte &= ~(1 << bit);
	if (++bit == 8)
	{
		if (state == 0)
			ft_handle_len(&len, &byte, &received, &state, &msg);
		else
			ft_handle_msg(&len, &received, &state, &msg, byte, info->si_pid);
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}*/