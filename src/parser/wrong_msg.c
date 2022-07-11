#include <stdio.h>

int	wrong_msg_argv(void)
{
	printf("Error\n");
	printf("You must input exactly one scene in the format .rt\n");
	return (1);
}

int	wrong_msg_open(char argv)
{
	printf("Error\n");
	perror(argv);
	return (1);
}
