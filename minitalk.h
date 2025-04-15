#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
//# include "ft_printf/ft_printf.h"
//# include "libft/libft.h"

void	send_char(char c, int pid);
void    handle_signal(int sig);

#endif