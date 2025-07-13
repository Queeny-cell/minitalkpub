#include "../include/minitalk.h"

int	global_bit = 0;

void	ft_sigprint(int sig)
{
	if (sig == SIGUSR1)
		global_bit = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received !\n");
		exit(EXIT_SUCCESS);
	}
}

static void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		global_bit = 0;
		if ((i >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while(global_bit == 0)
			pause();
	}
}
static void	ft_send_len(int pid, int len)
{
	int	i;

	i = 0; //metre i++ avant ?
	while (i < 4)
	{
		char byte = (len >> (i * 8)) & 0xFF;
		ft_send_bits(pid, byte);
		i++;
	}
}
static void	ft_send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_bits(pid, str[i]);
		i++;
	}
	ft_send_bits(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	len;
	char	*msg;

	i = 0;
	len = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		len = ft_strlen(msg);
		signal(SIGUSR1, &ft_sigprint);
		signal(SIGUSR2, &ft_sigprint);
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_send_len(pid, len);
	ft_send_str(pid, argv[2]);
	return (0);
}