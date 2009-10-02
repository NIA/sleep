#pragma once

#include <windows.h>
#include <cstdio>

bool is_integer(const char *str);       // Checks whether given string contains an integer number
void sleep(const char *arg);            // Parses argument and sleeps

// Printing messages:

void usage();                           // Prints usage message
void wrong_parameter(const char *param);// Prints wrong parameter message
