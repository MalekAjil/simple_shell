#include "shell.h"
/*
* get_line - reads string from the stream
* @lineptr: pointer to the line
* Return: return number of characters or -1 on failure.
*/
ssize_t get_line(char *lineptr)
{	
	size_t n = 0;
	ssize_t c = 0;

	c = getline(&lineptr, &n, stdin);
	if (c == -1)
	{
		free(lineptr);
		if (isatty(0) != 0)
			write(1, "\n", 1);
		exit(0);
	}
	if (lineptr[c - 1] == '\n' || lineptr[c - 1] == '\t')
		lineptr[c - 1] = '\0';
	for (n = 0; lineptr[n]; n++)
	{
		if (lineptr[n] == '#' && lineptr[n - 1] == ' ')
		{
			lineptr[n] = '\0';
			break;
		}
	}
	return (c);
}
