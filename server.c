#include "utils.h"

int reverse_bits(unsigned char byte)
{
	unsigned char reversed = 0;
	int i;

	i = 0;
	while (i < 8)
	{
		reversed = reversed * 2 + (byte % 2);
		byte /= 2;
	}
	return reversed;
}

void handler(int sig)
{
	static int rtn = 0;
	static int i = 0;

	if (sig == SIGUSR1)
		rtn = rtn | (1 << i);
	i++;
	if (i == 7)
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
