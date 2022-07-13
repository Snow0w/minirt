#include <parser.h>
#include <stddef.h>
#include <libft.h>
#include <stdlib.h>

static int	init_ambient_data(t_vlist **scene_arg, t_ambient *data)
{
	data = malloc(sizeof(t_ambient));
	if (!data)
		return (1);
	if (vlist_create_add_back(scene_arg, (void *) data, AMBIENT))
	{
		free(data);
		return (1);
	}
	return (0);
}

int	ambient_pars_ratio_token(t_ambient *data, char *str, t_unsizet token)
{
	double	ratio;
	int		flag;

	flag = 0;
	ratio = unsecure_pseudo_atof(str + token.index, &flag);
	if (flag)
		return (1);
	if (ratio < 0.0 || ratio > 1.0)
		return (1);
	data->ratio = ratio;
	return (0);
}

int	ambient_pars_rgb_token(t_ambient *data, char *str, t_unsizet token)
{
	if (!check_two_commas_in_token(str, token))
		return (1);
	if (check_valid_rgb_format(str, token))
		return (1);
	data->rgb.r = ft_atoi(str + token.index);
	while (str[token.index] != ',')
		token.index++;
	token.index++;
	data->rgb.g = ft_atoi(str + token.index);
	while (str[token.index] != ',')
		token.index++;
	token.index++;
	data->rgb.b = ft_atoi(str + token.index);
	if (data->rgb.r < 0 || data->rgb.r > 255)
		return (1);
	if (data->rgb.g < 0 || data->rgb.g > 255)
		return (1);
	if (data->rgb.b < 0 || data->rgb.b > 255)
		return (1);
	return (0);
}

int	hub_ambient_token(t_ambient *data, char *str, t_unsizet token, size_t cnt)
{
	if (cnt == 0)
		return (ambient_pars_ratio_token(data, str, token));
	if (cnt == 1)
		return (ambient_pars_rgb_token(data, str, token));
	return (1);
}

int	ambient_parsing(t_vlist **scene_arg, char *str, int *flag)
{
	t_unsizet	token;
	int			ret;
	size_t		cnt;
	t_ambient	*data;

	data = NULL;
	if (init_ambient_data(scene_arg, data))
		return (1);
	token.index = 0;
	token.offset = 0;
	cnt = 0;
	ret = find_next_token(str, &token);
	while (!ret && !(*flag))
	{
		cnt++;
		if (hub_ambient_token(data, str, token, cnt))
			*flag = 1;
		token.index += token.offset;
		ret = find_next_token(str, &token);
	}
	if (cnt != AMBIENT_PARS_NUMB)
		*flag = 1;
	return (0);
}
