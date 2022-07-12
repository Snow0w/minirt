#include <fcntl.h>
#include <stdlib.h>
#include <get_next_line.h>

int	add_new_scene_arg(t_vlist **scene_arg, char *str, int *flag)
{
	if (*str == '\n')
		return (0);
	if (ft_strlen(str) < 4)
	{
		*flag = 0;
		return (0);
	}
	if (!ft_strncmp(str, "A ", 2))
		return (ambient_parsing(scene_arg, str + 1, flag));
	if (!ft_strncmp(str, "C ", 2))
		return (camera_parsing(scene_arg, str + 1, flag));
	if (!ft_strncmp(str, "L ", 2))
		return (light_parsing(scene_arg, str + 1, flag));
	if (!ft_strncmp(str, "pl ", 3))
		return (plane_parsing(scene_arg, str + 2, flag));
	if (!ft_strncmp(str, "sp ", 3))
		return (sphere_parsing(scene_arg, str + 2, flag));
	if (!ft_strncmp(str, "cy ", 3))
		return (cylinder_parsing(scene_arg, str + 2, flag));
	*flag = 0;
	return (0);
}

int	common_parser_work(char *argv, t_vlist **scene_arg)
{
	int		fd;
	char	*str;
	int		flag;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (wrong_msg_open(argv));
	flag = 1;
	str = get_next_line(fd);
	while (str && flag)
	{
		if (add_new_scene_arg(scene_arg, str, &flag))
			return (free_vlist_and_std_error(scene_arg, str)); //need to erite
		free(str);
		str = get_next_line(fd);
	}
	if (!flag)
	{
		free(str); //maybe
		free_vlist(scene_arg); //need to write
		return (wrong_msg_file_parsing()); //need to erite
	}
	return (0);
}
