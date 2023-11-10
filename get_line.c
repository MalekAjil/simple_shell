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
	printf("%s\n", buf);
	
	if ((buf_index = str_cpy(*lineptr, buf)) > 0)
		printf("%lu, %s, %s\n", buf_index, buf, *lineptr);
	return (buf_index);
}
