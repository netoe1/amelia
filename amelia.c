#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <math.h>

const char *lower_letters = "abcedfghijklmnopqrstuvwxyz";
const char *upper_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numbers = "0123456789";
const char *specials = "!@#$%¨&*()_-";

char *ret = NULL;
long int max_combinations = 0;

void sig_handler()
{ // Handler to signals
	printf("amealia-said-> Cleaning memory... (avoid memory-leaks)\n");
	free(ret);
}

void sig_config()
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGTSTP, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGILL, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGABRT, sig_handler); // Setting signals every kind of cases.
}

void push_to_ret(char letter)
{
	if (ret == NULL)
	{
		ret = (char *)malloc(sizeof(char));
		ret[0] = '\0';
		return;
	}

	unsigned int index_null = 0;
	unsigned int initial_len = strlen(ret) + 1; // Counting null char.

	for (unsigned int i = 0; i < initial_len; i++)
	{
		if (ret[i] == '\0')
		{
			// In case the null char may be found.
			char *realloc_return = (char *)realloc(ret, sizeof(char) * initial_len + 1);
			if (!realloc_return)
			{
				perror("amelia-said-> Cannot alloc.");
				free(ret);
				free(realloc_return);
				exit(EXIT_FAILURE);
			}
			ret[i] = letter;
			ret[i + 1] = '\0';
			break;
		}
	}
}

void generatePassword(const char *base, int len);

int main(int argc, char **argv)
{

	free(ret);
	return 0;
}
