#pragma once

#include <windows.h>
#include <cstdio>

#pragma warning(disable : 4996)

bool is_integer(const char *str);       // Checks whether given string contains an integer number
void parse(const char *arg);            // Parses given string and calls sleep with proper arguments
void sleep(const char *arg, int multiplier = 1);  // Converts string into number and sleeps arg * multiplier seconds

// Printing messages:

void usage();                           // Prints usage message
void wrong_parameter(const char *param);// Prints wrong parameter message
