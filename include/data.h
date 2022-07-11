#ifndef DATA_H
# define DATA_H

typedef struct	s_vlist
{
	int				type;
	void			*arg;
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
	double	r;
	double	b;
	double	g;
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
#endif

