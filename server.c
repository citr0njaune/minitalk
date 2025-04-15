#include "minitalk.h"

void    handle_signal(int sig) //recu signal ?
{
    static unsigned char	current_char; //construction du bit, bit par bit 0000 0000
	static int				bit_index; 

	current_char |= (signal == SIGUSR1); // si le signal est bien SIGUSR1( bit = 1) alors on ajoute 1 dans le 0000 000X sur le X et ensuite le decale petit a petit avec la ligne 20, info+ c'est a chaque signal recu 
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
    ft_printf("SERVER PID: %d\n", get_pid());
    signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
    return (0);
}
