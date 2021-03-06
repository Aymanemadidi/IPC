#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}
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

void SIG_HAN(int sign)
{
	static size_t	i;
	static int		bit;
	clock_t 		begin;
	static char		buf[10000];//stores ascii codes

	if (i == 0)
		begin = clock();
	if (--bit == -1)
	{
		bit = 6;
		++i;
	}
	//buf[i] &= /*~(1 << 7)*/127;
	if (sign == SIGUSR1)
	{
		buf[i] |= (1 << bit);//adds the corresponding 1 bit ascii value to buf[i]
		//write(STDOUT_FILENO, &buf[i], 1);
		//printf("%d\n", bit);
		//printf("%d\n", i);
		//printf("%d\n", buf[i]);
	}
		
	else if (sign == SIGUSR2)
	{
		buf[i] &= ~(1 << bit);//keeps buf[i] the same
		//write(STDOUT_FILENO, &buf[i], 1);
	}
		
	if (buf[i] == 127)
	{
		/*if (buf[i] == 127)
			printf("true\n");*/
		buf[i] = 0;
		//write(STDOUT_FILENO, buf, i + 1);
		write(1,"\n",1);
		clock_t end = clock();
		//printf("time spent: %lu\n", (end - begin) / CLOCKS_PER_SEC);
		ft_memset(buf, '\0', 99);
		i = 0;
		bit = 0;
	}

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

    while (1)
	{
		signal(SIGUSR1, SIG_HAN);
		signal(SIGUSR2, SIG_HAN);
	}

}