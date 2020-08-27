#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void 	type_promt()
{
	static int	first_time = 1;

	if (first_time)     // clear screen for the first time
	{
		const char * CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J ";
		write (STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printf("# ");    //display promt
}

void 	read_command(char cmd[], char *par[])
{
	char 	line[1024];
	int 	count = 0;
	int 	i = 0;
	char	*array[100];
	char 	*pch;

	// Read one line
	while (1)//  Попробовать заменить на while(1)
	{
		int c = fgetc( stdin );
		line[count++] = (char) c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	pch = strtok(line, "\n");

	// Разбор строки на слова
	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, "\n");
	}

	// Первое слово - это команда
	strcpy(cmd, array[0]);

	// Другие параметры
	for (int j = 0; j < i; j++)
		par[j] = array[j];
	par[i] = NULL;   // NULL - завершить список параметров
}

int main()
{
	char	cmd[100];
	char 	command[100];
	char 	*parametrs[20];
	char 	*env[] = { (char *) "PATH=/bin", 0 };
	while (1)					// repeat forever
	{
		type_promt();           // display promt on screen
		read_command(command, parametrs);  // read input from terminal
		if (fork() != 0)
			wait (NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parametrs, env);       // Выполнить команду
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}