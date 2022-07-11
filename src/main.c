#include <minirt.h>
#include <parser.h>

int	main(int argc, char **argv)
{
	t_vlist	*scene_arg;

	if (argc != 2 || check_scene_format(argv[1]))
		return (wrong_msg_argv());
	if (common_parser_work(argv[1], &scene_arg))
		return (1);
	return (0);
}
