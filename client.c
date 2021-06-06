#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int* decToBinary(int n)
{
    // array to store binary number
    int *binaryNum = malloc(32 * sizeof(int));
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    binaryNum[i] = '\0';
    return (binaryNum);
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')  
        i++;
    return (i);    
}

int main(int argc, char **argv)
{   
    int pid;
    int buff[100];
    int i;
    int len;
    int *binaryNum = malloc(32 * sizeof(int));
    pid = atoi(argv[1]);

    char *s = "hello";
    len = ft_strlen(s);
    i = 0;

    printf("%c\n", s[0]);
    printf("%d\n", (int)s[0]);
    i = 32;
    while (i >= 32 && i <= 126)
    {   
        if ((int)s[0] == i)
            break;
        i++;
    }
    binaryNum = decToBinary(i);

    printf("%d\n", i);
    i = 7;
    while(i > -1)
    {
        printf("%d", binaryNum[i]);
        i--;
    }

    /*kill(pid, SIGUSR1);
    usleep(1000);
    kill(pid, SIGUSR1);
    usleep(1000);
    kill(pid, SIGUSR1);
    usleep(1000);
    kill(pid, SIGUSR1);
    usleep(1000);
    kill(pid, SIGUSR1);*/

    i = 0;
    while (i < 7)
    {
        if (binaryNum[i] == 1)
        {
            kill(pid, SIGUSR1);
            usleep(1000);
        }
        else
        {
            kill(pid, SIGUSR2);
            usleep(1000);
        }
        i++;
    }



    /*if (argc < 3)
	{
		write(2, "usage: ./client [pid server] [message]\n", 39);
		return (1);
	}*/
    //kill(pid, SIGUSR1);
}