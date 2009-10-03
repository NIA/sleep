#pragma once

#include <windows.h>
#include <cstdio>

#pragma warning(disable : 4996)

enum Result
{
    RESULT_OK, RESULT_ERROR
};

// Checks whether given string represents an integer number
bool is_integer(const char *str);

// Parses given string and calls sleep with proper arguments
Result parse(const char *arg);

// Converts string into number and sleeps arg * multiplier seconds
Result sleep(const char *arg, int multiplier = 1);
