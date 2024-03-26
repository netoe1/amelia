#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#define setUTF() setlocale(LC_ALL, "")
#define function_arg argv[1]
#define arg_count argc
void help();
void badUsage();
bool isStrNull(char *str);
int main(int argc, char **argv)
{
    setUTF();

    if (arg_count == 2)
    {
        if (!isStrNull(function_arg))
        {
            return;
        }

        if (strcmp("--help", function_arg) || strcmp("-h", function_arg))
        {
            help();
        }

        return;
    }
    else if (arg_count == 3)
    {
        if (strcmp("--pattern", function_arg) || strcmp("-p", function_arg))
        {
        }
    }

    help();

    return EXIT_FAILURE;
}
void help()
{
    puts("Testing help message.");
}

void badUsage()
{
    puts("hash-said-> You set an invalid string to use as a arg's.\nPlease, set a valid, different than NULL.");
}

bool isStrNull(char *str)
{
    if (str != NULL || str[0] != '\0')
    {
        return true;
    }

    return false;
}