#include "sleep.h"

// Printing messages:

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

// Main
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage();
        return RESULT_ERROR;
    }
    else
    {
        if( strcmp(argv[1], "/help") == 0 || strcmp(argv[1], "/?") == 0 )
        {
            help();
            return RESULT_OK;
        }
        else
        {
            return parse(argv[1]);
        }
    }
}

// Parses given string and calls sleep with proper arguments
Result parse(const char *arg)
{
    size_t length = strlen( arg );

    // chop last character
    char *chopped = new char[length + 1];
    strcpy( chopped, arg );
    chopped[length-1] = 0;

    char last = arg[length-1];
    switch( last )
    {
    case 's' :
        return sleep( chopped );
    case 'm' :
        return sleep( chopped, 60 );
    case 'h' :
        return sleep( chopped, 60*60 );
    case 'd' :
        return sleep( chopped, 60*60*24 );
    default:
        return sleep( arg );
    }
}

// Checks whether given string represents an integer number
bool is_integer(const char *str)
{
    size_t length = strlen( str );
    for( size_t i = 0; i < length; ++i )
        if( !isdigit(str[i]) && !isspace(str[i]) )
            return false;
    return true;
}

// Converts string into number and sleeps for arg * multiplier seconds
Result sleep(const char *arg, int multiplier)
{
    if( !is_integer(arg) )
    {
        wrong_parameter( arg );
        return RESULT_ERROR;
    }
    else
    {
        int n = atoi(arg);
        Sleep(n*1000*multiplier);
        return RESULT_OK;
    }
}

