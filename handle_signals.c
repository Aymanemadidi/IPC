#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>

void handler(int num)
{
    write(STDOUT_FILENO, "I won't die!\n", 13);
}

int main(void)
{
    signal(SIGINT, handler);
    while (1)
    {
        printf("booooooo %d\n", getpid());
        sleep(1);
    }
    return (1);
}