#include "minitalk.h"

void    sig_han(int     signal)
{
        if (signal == SIGUSR1)
                write(1, "the server acknowledge the message\n", 35);
}

void    ft_send_encrypted_bit(char c,int pid)
{
        int     i;

        i = 7;
        while(i >= 0)
        {
                if(((c >> i) & 1) == 1)
                        kill(pid, SIGUSR1);
                else
                        kill(pid, SIGUSR2);
                usleep(20000);
                i--;
        }
}
void    ft_send_str(char *str,int pid)
{
        int     i;

        i = 0;
        while(str[i])
        {
                ft_send_encrypted_bit(str[i], pid);
                i++;
        }
        ft_send_encrypted_bit('\0', pid);
}
int main(int ac, char **av)
{
	int	pid;

        signal(SIGUSR2, sig_han);
        signal(SIGUSR1, sig_han);
        if (ac != 3 || ft_strlen(av[1]) > 10)
        {
                ft_putstr("make sure the number of argument is 3 and PID is less than 10 digits\n");
                return (0);
        }
        pid = ft_atoi(av[1]);
        ft_send_str(av[2], pid);
}
