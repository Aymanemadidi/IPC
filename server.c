#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int		len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char *str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')  
        i++;
    return (i);    
}

void SIG1_HAN()
{
    write(1,"SIGUSR1 handled\n", 16);
}

void SIG2_HAN()
{
    write(1,"SIGUSR2 handled\n", 16);
}

int main(int argc, char **argv)
{   
    int server_pid;

    (void)argv;
	if (argc != 1)
	{
		write(STDERR_FILENO, "usage: ./server\n", 16);
		return (1);
	}

    server_pid = getpid();

    write(1, ft_itoa(server_pid), ft_strlen(ft_itoa(server_pid))); 
    write(1, "\n", 1);

    signal(SIGUSR1, SIG1_HAN);
    signal(SIGUSR2, SIG2_HAN);
    

    while (1) {}

}