#include "utils.h"

int main(int ac, char **av)
{
	int pid;
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac != 3)
	{
		ft_printf("Usage: ./client [server pid] [message]\n");
		return 0;
	}
	else if(ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			while (j < 8)
			{
				if (av[2][i] & (1 << j))
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				j++;
				usleep(100);
			}
			j = 0;
			i++;
		}
	}
}
