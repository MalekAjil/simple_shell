#include "shell.h"

/**
 *reallocate_memory - allocate memory to the pointer
 *@lineptr: pointer to the line input
 *@n: parameter to take in size
 *
 *Return: return -1 on failure 0 on success.
 */
int reallocate_memory(char **lineptr, size_t *n)
{
	char *new_line = (char *)realloc(*lineptr, *n);

	if (new_line != NULL)
	{
		*lineptr = new_line;
		*n *= 2;
		return (-1);
	}
	*lineptr = new_line;
	return (0);
}
/**
*read_line - function to read to stream and store to line pointer
*@stream: pointer to file stream address
*@line: pointer to a line
*@n: size of input
*Return: return -1 on failure otherwise return number of bytes.
*/
ssize_t read_line(FILE *stream, char *line, size_t n)
{
	ssize_t bytes_read = 0;

	bytes_read = fread(line, 1, n, stream);
	if (bytes_read < 0)
	{
	return (-1);
	}
	else if (bytes_read == 0)
	{
	return (-1);
	}
	return (bytes_read);
}
/**
*get_line - function to get line from stream
*@lineptr: pointer to the line
*@n: array for n chars
*@stream: pointer to the file stream
*Return: return -1 on failure and return length of line on success.
*/
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	char buf[MAX_BUFFER_SIZE];
	ssize_t bytes_read = 0;
	size_t buf_index = 0;
	size_t line_length = 0;

	if (!lineptr || !n || !stream)
	{
		return (-1);
	}
	if (*n == 0)
	{
		*n = 100;
	}
	if (bytes_read <= 0)
	{
		bytes_read = read_line(stream, buf, MAX_BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		return (-1);
	}
	while (buf_index < (size_t)bytes_read && buf[buf_index] != '\n')
	{
	if (line_length + 1 >= *n)
	{
		int reallocated = reallocate_memory(lineptr, n);

		if (reallocated == -1)
		{
			return (-1);
		}
	}
	(*lineptr)[line_length++] = buf[buf_index++];
	}
	(*lineptr)[line_length] = '\0';
	buf_index++;
	if (buf_index >= (size_t)bytes_read)
	{
		bytes_read = 0;
	}
	return (line_length);
}
/**
* get_line - reads buffer from the stream
* @lineptr: pointer to the line
* @n: parameter for number to take input
* @stream: array for the buffe
* Return: return number of characters or -1 on failure.
*/
ssize_t get_line1(char **lineptr, size_t *n, FILE *stream)
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
