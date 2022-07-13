#include <stddef.h>
#include <libft.h>

static double	atof_help(char *str, size_t *i, int *flag, double out)
{
	size_t	e;

	e = 0;
	(*i)++;
	while (str[*i] && ft_isdigit(str[*i]))  
	{
		out = out * 10.0 + (str[*i] - '0');
		e++;
		(*i)++;
	}
	if (e == 0)
		*flag = 1;
	while (e)
	{
		out = out / 10.0;
		e--;
	}
	return (out);
}

static void	sign_atof(double *sign, char *str, size_t *i)
{
	if (str[*i] == '-')
		*sign = -1.0;
	if (str[*i] == '-')
		(*i)++;
}

double	unsecure_pseudo_atof(char *str, int *flag)
{
	double	sign;
	size_t	i;
	double	out;
	size_t	cnt;

	i = 0;
	sign = 1.0;
	sign_atof(&sign, str, &i);
	out = 0.0;
	cnt = 0;
	while (str[i] && ft_isdigit(str[i]))  
	{
		out = out * 10.0 + str[i] - '0';
		cnt++;
		i++;
	}
	if (cnt == 0)
		*flag = 1;
	if (str[i] == '.')
		out = atof_help(str, &i, flag, out);
	if (str[i] != ' ' && str[i] != ',' && str[i] != '\n' && str[i] != '\0')
		*flag = 1;
	return (out * sign);
}
