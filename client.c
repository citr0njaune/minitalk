#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	idx_bit;

	idx_bits = 8
	while (idx_bit--)
	{
		if (c >> idx_bits & 1) //bit idx_bit de c vaut bien 1 ?
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		idx_bit--;
	}
}

int main    (int ac, char **av) // ./client pid_server "le message"
{
	int	i;
	int	pid;

	i = 0;
    if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("error\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	ft_putstr_fd("Received: ", 1);
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
	send_char('\0', pid);
    return (0);
}
