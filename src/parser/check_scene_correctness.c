#include <libft.h>

int	check_scene_format(char *scene_name)
{
	size_t	len;

	len = ft_strlen(scene_name);
	if (len < 4)
		return (1);
	if (!ft_streq(scene_name + len - 3, ".rt"))
		return (1);
	return (0);
}
