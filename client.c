/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chphan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:46:23 by chphan            #+#    #+#             */
/*   Updated: 2025/04/22 14:46:26 by chphan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	idx_bit;

	idx_bit = 0;
	while (idx_bit < 8)
	{
		if ((c >> (7 - idx_bit)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		idx_bit++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3 || !ft_strlen(av[2]))
	{
		ft_printf("error\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	ft_putstr_fd("Received", 1);
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
