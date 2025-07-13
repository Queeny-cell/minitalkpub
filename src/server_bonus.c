#include "../include/minitalk.h"

/* void	ft_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	else if (signal == SIGUSR2)
		i &= ~(1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		else
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		i = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
} */


void	ft_handler(int signal, siginfo_t *info, void *context)
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
				ft_printf("%s\n", msg);
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
}


int	main(int argc, char **argv)
{
	int	pid;
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
