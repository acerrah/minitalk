#include "utils.h"

void handler(int sig)
{
	static int rtn = 0;
	static int i = 0;

	if (sig == SIGUSR1)
		rtn = rtn | (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &rtn, 1);
		i = 0;
		rtn = 0;
	}
}

int main()
{
	ft_printf("PID: %d",getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
