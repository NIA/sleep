#include "sleep.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        usage();
    else
        sleep(argv[1]);
    return (0);
}

bool is_integer(const char *str)
{
    size_t length = strlen( str );
    for( size_t i = 0; i < length; ++i )
        if( !isdigit(str[i]) && !isspace(str[i]) )
            return false;
    return true;
}

void sleep(const char *arg)
{
    int n = atoi(arg);
    if( n == 0 && !is_integer(arg) )
        wrong_parameter( arg );
    Sleep(n*1000);
}

// Printing messages:

void usage()
{
    printf("Usage: sleep number\nExample: sleep 5");
}

void wrong_parameter(const char *param)
{
    printf("sleep: wrong time interval value: `%s'", param);
    // TODO: print 'try --help blah blah blah'
}
