#include "minitalk.h"

void    handle_signal(int sig)
{
    static unsigned char	current_char;
	static int				bit_index; 

	current_char |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
        if (current_char == '\0')
            ft_printf("\n");
        ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int main(void)
{
    ft_printf("SERVER PID: %d\n", getpid());
    signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
    return (0);
}
