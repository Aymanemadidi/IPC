#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void INThandler(int);

void main(void)
{
    if (signal(SIGINT, SIG_IGN) != SIG_IGN)
        signal(SIGINT, INThandler);
    while (1)
        pause();
}

void INThandler(int num)
{
    char c;
    signal(SIGINT, SIG_IGN);   
    printf("Ouch, did you hit Ctrl-C?\n,Do you really want to quit [y/n]?");
    c = getchar();
    if (c == 'y' || c == 'Y')
        exit(0);    
    else
        signal(SIGINT, INThandler);    
}