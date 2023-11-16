#include "shell.h"

/**
 * get_path - return the path
 * @cmds: the commands
 * @line: the line pointer
 * Return: the full  path
 */
char* get_path(char **cmds, char *line)
{
	char *tk = NULL, *path = NULL, *tmp = NULL, *cc = NULL;
	static char temp[256];
	int wcount = 0, flg = 0, w = 0, len = 0;
	struct stat st;

	path = str_dup(line);
	wcount = str_words(path);
	tk = strtok(path, ": =");
	while (tk != NULL)
	{
		cc = str_cat(temp, cmds, tk);
		if (stat(cc, &st) == 0)
		{
			tmp = cc;
			flg = 1;
			break;
		}
		if (w < wcount - 2)
		{
			len = str_len(tk);
			if (tk[len + 1] == ':')
			{
				if (stat(cmds[0], &st) == 0)
				{
					tmp = cmds[0];
					flg = 1;
					break;
				}
			}
		}
		w++;
		tk = strtok(NULL, ":");
	}
	if (flg == 0)
		tmp = cmds[0];
	free(path);
	return (tmp);
}
