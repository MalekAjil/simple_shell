#include "shell.h"

/**
*get_line - reads buffer from the stream
*@lineptr: pointer to the line
*@n: parameter for number to take input
*@stream: array for the buffer
*
*Return: return number of characters or - 1 on failure.
*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static char buf[MAX_BUFFER_SIZE];
	static size_t buf_index = (0);
	static ssize_t bytes_read = (0);
	size_t line_length = (0);
	char *line = *lineptr;

	if (!lineptr || !n || !stream)
	return (-1);
	if (*n == 0)
	*n = 100;
	if (bytes_read <= 0)
	{
		bytes_read = read(fileno(stream), buf, MAX_BUFFER_SIZE);

	if (bytes_read < 0)
	return (-1);
	else if
		(bytes_read == 0)
	return (-1);
		buf_index = 0;
	}
	while
		(buf_index < (size_t)bytes_read && buf[buf_index] != '\n')
	{
		if (line_length + 1 >= *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			line = *lineptr;
		if (!line)
		return (-1);
		}
		line[line_length++] = buf[buf_index++];
	}
	line[line_length] = '\0';
	buf_index++;
	if ((ssize_t)buf_index >=
			bytes_read)
		bytes_read = 0;
	return (line_length);
}
