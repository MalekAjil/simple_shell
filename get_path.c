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
	wcount = w_count(path, ':');
	tk = strtok(path, ": =");
	while (tk != NULL)
	{
		cc = str_cat3(temp, cmds[0], tk);
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

/**
 * str_cat3 - concats path members and /
 * @str1: concated string
 * @str2: string array
 * @str3: the path member
 * Return: concated string
 */
char *str_cat3(char *str1, char *str2, char *str3)
{
	int i = 0;

	for (i = 0; i < 256; i++)
		str1[i] = 0;
	i = str_len(str3) + str_len(str2) + 2;
	str_cat(str1, str3);
	str_cat(str1, "/");
	str_cat(str1, str2);
	str1[i - 1] = '\0';
	return(str1);
}
