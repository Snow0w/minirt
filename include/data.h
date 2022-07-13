#ifndef DATA_H
# define DATA_H

#include <stddef.h>

typedef struct	s_unsizet
{
	size_t	index;
	size_t	offset;
}				t_unsizet;

typedef struct	s_vlist
{
	int				type;
	void			*data;
	struct s_vlist	*next;

}				t_vlist;

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct	s_rgb
{
	int	r;
	int	b;
	int	g;
}				t_rgb;

typedef struct	s_ambient
{
	double	ratio;
	t_rgb	rgb;
}				t_ambient;

# define AMBIENT  0
# define CAMERA   1
# define LIGHT    2
# define SPHERE   3
# define CYLINDER 4
# define PLANE    5

# define AMBIENT_PARS_NUMB  2
# define CAMERA_PARS_NUMB   1
# define LIGHT_PARS_NUMB    2
# define SPHERE_PARS_NUMB   3
# define CYLINDER_PARS_NUMB 4
# define PLANE_PARS_NUMB    5
#endif

