#include "sleep.h"

// Printing messages:
// TODO: print to stderr

inline void try_help()
{
    fprintf(stderr, "Try sleep --help for more information\n");
}

inline void usage()
{
    fprintf(stderr, "Usage: sleep number[suffix]\nExample: sleep 5m\n");
    try_help();
}

inline void wrong_parameter(const char *param)
{
    fprintf(stderr, "sleep: wrong time interval value: `%s'\n", param);
    try_help();
}

inline void help()
{
    printf( "sleep.exe, an analog of UNIX sleep program\n"
            "Pauses execution for given time\n\n"
            "Usage: sleep number[suffix]\n"
            "       sleep /help\n\n"
            "  nubmer      the length of time interval, in seconds, minutes, hours or days, depending on suffix\n"
            "  suffix      unit of time. Can be:\n"
            "                s  - seconds\n"
            "                m  - minutes\n"
            "                h  - hours\n"
            "                d  - days\n"
            "              may be omitted, default is s\n"
            "  /help (/?)  prints this message and exits\n\n"
            "(C) Ivan Novikov, 2009\n" );
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage();
    }
    else
    {
        if( strcmp(argv[1], "/help") == 0 || strcmp(argv[1], "/?") == 0 )
            help();
        else
            parse(argv[1]);
    }
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

