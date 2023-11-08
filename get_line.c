#include "shell.h"

/**
* get_line - reads buffer from the stream
* @lineptr: pointer to the line
* @n: parameter for number to take input
* @stream: array for the buffe
* Return: return number of characters or -1 on failure.
*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static char buf[MAX_BUFFER_SIZE];
	static size_t buf_index = 0;
	static ssize_t bytes_read = 0;
	char *line = NULL;

	if (!n || !stream)
		return (-1);
	if (*n == 0)
		*n = 100;
	bytes_read = read(fileno(stream), buf, MAX_BUFFER_SIZE);
	if (bytes_read <= 0)
		return (-1);

	line = malloc(sizeof(char) * bytes_read);
	if (line == NULL)
		return (-1);
	while (buf_index < (size_t)bytes_read && buf[buf_index] != '\n')
	{
		line[buf_index] = buf[buf_index];
		buf_index++;
	}
	line[buf_index] = '\n';
	*lineptr = line;
	return (buf_index);
}
