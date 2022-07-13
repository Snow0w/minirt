#include <minirt.h>
#include <parser.h>
#include <stdio.h>

void	print_vlist(t_vlist *scene_arg)
{
	int	i;
	t_ambient *ambient;

	i = 0;
	while (scene_arg)
	{
		if (scene_arg->type == AMBIENT)
		{
			ambient = (t_ambient *) scene_arg->data;
			printf("%d - ambient, %lf - ratio, %d,%d,%d - rgb\n", i, ambient->ratio, ambient->rgb.r, ambient->rgb.g, ambient->rgb.b);

		}
		scene_arg = scene_arg->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_vlist	*scene_arg;

	if (argc != 2 || check_scene_format(argv[1]))
		return (wrong_msg_argv());
	if (common_parser_work(argv[1], &scene_arg))
		return (1);	
	print_vlist(scene_arg);
	return (0);
}
