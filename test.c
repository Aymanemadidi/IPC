#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    clock_t begin = clock();
    unsigned long long i = 0;
    while ( i < 10000000000)
    {
        i++;
    }
    clock_t end = clock();
    printf("time spent: %lu\n", (end - begin) / CLOCKS_PER_SEC);
    printf("finished\n");
    return (0);
}