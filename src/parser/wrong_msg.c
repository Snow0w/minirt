#include <stdio.h>
#include <stdlib.h>
#include <parser.h>

int	wrong_msg_argv(void)
{
	printf("Error\n");
	printf("You must input exactly one scene in the format .rt\n");
	return (1);
}

int	wrong_msg_open(char *argv)
{
	printf("Error\n");
	perror(argv);
	return (1);
}

int	free_vlist_and_std_error(t_vlist **scene, char *str)
{
	free(str);
	free(scene);
	printf("Error\n");
	perror("Malloc probably");
	return (1);
}

int	wrong_msg_file_parsing(char *file)
{
	printf("Error\n");
	printf("Misconfiguration in file %s\n", file);
	return (1);
}
