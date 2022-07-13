#include <data.h>
#include <stdlib.h>

void	free_vlist(t_vlist **scene_arg)
{
	t_vlist	*cur;
	t_vlist	*prev;

	cur = *scene_arg;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		if (prev->data)
			free(prev->data);
		free(prev);
	}
}

t_vlist	*vlist_new(void *data, int type)
{
	t_vlist	*list;

	list = malloc(sizeof(t_vlist));
	if (!list)
		return (NULL);
	list->data = data;
	list->type = type;
	list->next = NULL;
	return (list);
}

int	vlist_create_add_back(t_vlist **lst, void *data, int type)
{
	t_vlist	*cur;

	if (!*lst)
	{
		*lst = vlist_new(data, type);
		if (!(*lst))
			return (1);
	}
	else
	{
		cur = *lst;
		while (cur->next)
			cur = cur->next;
		cur->next = vlist_new(data, type);
		if (!(cur->next))
			return (1);
	}
	return (0);
}
