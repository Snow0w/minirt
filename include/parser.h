#ifndef PARSER_H
# define PARSER_H

# include <data.h>

int		wrong_msg_argv(void);
int		wrong_msg_open(char *argv);
int		free_vlist_and_std_error(t_vlist **scene, char *str);
int		wrong_msg_file_parsing(char *file);

int		check_scene_format(char *scene_name);
double	unsecure_pseudo_atof(char *str, int *flag);
int		find_next_token(char *str, t_unsizet *token);
int		check_two_commas_in_token(char *str, t_unsizet token);
int		check_valid_rgb_format(char *str, t_unsizet token);

int		vlist_create_add_back(t_vlist **lst, void *data, int type);
void	free_vlist(t_vlist **scene_arg);

int		ambient_parsing(t_vlist **scene_arg, char *str, int *flag);
#endif
