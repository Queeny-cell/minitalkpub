#include "../include/minitalk.h"

void	ft_handler(int signal, siginfo_t *info, void *context)
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