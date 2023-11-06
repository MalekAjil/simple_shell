#include "shell.h"

/**
 * print_env - prints the current environment
 * Return void
 */
void print_env()
{
	write(1, "env\n", 4);
}
