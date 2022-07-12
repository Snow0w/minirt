#include <parser.h>
/*
int	find_next_token(char *str, size_t *index, size_t *offset)
{
	space_skip(str, index);
	*offset = 0;
	if (str[*index] == '\n')
		return (1);
	if (!str[*index])
		return (2);
	while (str[*index + *offset] && str[*index + *offset] != ' '
		&& str[*index + *offset] != '\n')
		(*offset)++;
	return (0);
}
*/
int	find_next_token(char *str, t_unsizet *token)
{
	while (str[token->index] == ' ')
		(token->index)++;
	token->offset = 0;
	if (str[token->index] == '\n')
		return (1);
	if (!str[token->index])
		return (2);
	while (str[token->index + token->offset]
		&& str[token->index + token->offset] != ' '
		&& str[token->index + token->offset] != '\n')
		(token->offset)++;
	return (0);
}

//return 0 if token has 2 commas
int	check_two_commas_in_token(char *str, t_unsizet token)
{
	size_t	cnt;

	cnt = 0;
	while (token.offset)
	{
		if (str[token.index] == ',')
			cnt++;
		token.index++;
		token.offset--;
	}
	if (cnt == 2)
		return (0);
	return (1);
}

int	check_valid_rgb_format(char *str, t_unsizet token)
{
	while (token.offset)
	{
		if (str[token.index] != ',' || !ft_isdigit(str[token.index]))
			return (1);
		token.index++;
		token.offset--;
	}
	return (0);
}
