#include "sleep.h"

void usage()
{
    printf("Usage: sleep number\nExample: sleep 5");
}

void sleep(const char *arg)
{
    int n = atoi(arg);
    Sleep(n*1000);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        usage();
    else
        sleep(argv[1]);
    return (0);
}
