#include "sleep.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        usage();
    else
        parse(argv[1]);
    return (0);
}

void parse(const char *arg)
{
    size_t length = strlen( arg );
    char *chopped = new char[length + 1];
    strcpy( chopped, arg );
    chopped[length-1] = 0; // chop last character

    char last = arg[length-1];
    switch( last )
    {
    case 's' :
        sleep( chopped );
        break;
    case 'm' :
        sleep( chopped, 60 );
        break;
    case 'h' :
        sleep( chopped, 60*60 );
        break;
    case 'd' :
        sleep( chopped, 60*60*24 );
        break;
    default:
        sleep( arg );
        break;
    }
}

bool is_integer(const char *str)
{
    size_t length = strlen( str );
    for( size_t i = 0; i < length; ++i )
        if( !isdigit(str[i]) && !isspace(str[i]) )
            return false;
    return true;
}

void sleep(const char *arg, int multiplier)
{
    if( !is_integer(arg) )
    {
        wrong_parameter( arg );
    }
    else
    {
        int n = atoi(arg);
        Sleep(n*1000*multiplier);
    }
}

// Printing messages:
// TODO: print to stderr

void usage()
{
    printf("Usage: sleep number[suffix]\nExample: sleep 5m");
}

void wrong_parameter(const char *param)
{
    printf("sleep: wrong time interval value: `%s'", param);
    // TODO: print 'try --help blah blah blah'
}
