#include "minitalk.h"

void    signal_handler(int signal, siginfo_t *info, void *context)
{
        static int bit_tracker = 0;
        static char     c = 0;
        pid_t   s_pid;

        (void )context;
        s_pid = info -> si_pid;
        if (signal == SIGUSR1)
                c = (c << 1) | 1;
        else
                c = (c << 1);
        bit_tracker++;
        if(bit_tracker == 8)
        {
                if(c == '\0')
                        (write(1, "\n", 1), kill(s_pid, SIGUSR1));
                else
                        write(1, &c, 1);
                bit_tracker = 0;
                c = 0;
        }
        kill(s_pid, SIGUSR2);
}
int main()
{
        int     pid;
        struct sigaction sa;

        sa.sa_sigaction = signal_handler;
        sa.sa_flags = SA_SIGINFO;
        pid = getpid();
        sigemptyset(&sa.sa_mask);
        ft_putnbr(pid);
        write(1, "\n", 1);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while(1)
                pause();
}
