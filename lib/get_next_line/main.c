#include "get_next_line.h"
#include <stdio.h>


int main(int ac, char **av)
{
	char	*line;
	int		file_1;
	/*int		file_2;*/

	(void)ac;
	(void)av;
	file_1 = open("read_error.txt", O_RDONLY);
	/*file_2 = open("main.c", O_RDONLY);*/

	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);

	/*-------------------------------*/
	line = get_next_line(file_1);
	printf("line --> |%s|", line);
	free(line);
	return (0);
}
