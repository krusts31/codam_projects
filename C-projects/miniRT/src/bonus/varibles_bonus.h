/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   varibles_bonus.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:21:05 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:21:05 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIBLES_BONUS_H
# define VARIBLES_BONUS_H
# ifndef ROUND
#  define ROUND 0
# endif
# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef BMP_FILE_HEADER_SIZE
#  define BMP_FILE_HEADER_SIZE 14
# endif
# ifndef BMP_INFO_HEADER_SIZE
#  define BMP_INFO_HEADER_SIZE 40
# endif
# include <stddef.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}			t_vec;

typedef struct s_vec_i
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}			t_vec_i;

typedef struct s_vec_uc
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}			t_vec_uc;

typedef struct s_vec1
{
	float	r;
	float	g;
	float	b;
}			t_vec1;

/*
**		v1 is origin
**		v2 if direction
*/

typedef struct s_ray
{
	t_vec	v1;
	t_vec	v2;
}			t_ray;

typedef struct s_sc
{
	t_vec1		color;
	struct s_sc	*next;
}			t_sc;

typedef struct s_hit
{
	float	t;
	t_vec	p;
	t_vec	normal;
	t_vec1	color;
	t_vec	spec;
	t_sc	*diffuse;
	t_sc	*specular;
}			t_hit;

typedef struct s_sphere_difuse_var
{
	t_vec	*point;
	t_vec	*rand;
	t_vec	*one;
	t_vec	*tmp;
}			t_sphere_difuse_var;

typedef struct s_camera
{
	t_vec	origin;
	t_vec	lower_left_corner;
	t_vec	horizontal;
	t_vec	vertical;
}			t_camera;

typedef struct s_draw
{
	t_ray	ray;
	t_vec	p;
	t_vec1	col;
	t_vec1	new_col;
	int		x;
	int		y;
	int		t;
	int		n;
	float	u;
	float	v;
	t_vec_i	result;
}			t_draw;

typedef struct s_col_var
{
	t_hit	hit;
	t_vec	unit_dir;
	float	t;
	t_vec	new;
	t_vec	new1;
	t_vec	ret;
	t_vec	tmp;
	t_vec	random;
	t_ray	new_r;
	t_vec	some_vec;
}			t_col_var;

typedef struct s_sq
{
	t_vec		cor;
	t_vec		norm;
	t_vec_uc	col;
	float		side_size;
	const float	rotation;
	struct s_sq	*next;
}			t_sq;

/*
**	Plane
*/

typedef struct s_pl
{
	t_vec		cor;
	t_vec		norm;
	t_vec_uc	col;
	struct s_pl	*next;
}			t_pl;

/*
**	Cylinder
*/

typedef struct s_cy
{
	t_vec		cor;
	t_vec		norm;
	t_vec_uc	col;
	float		radius;
	float		height;
	struct s_cy	*next;
}			t_cy;

/*
**	Triangle
*/

typedef struct s_tr
{
	t_vec		cor1;
	t_vec		cor2;
	t_vec		cor3;
	t_vec_uc	col;
	struct s_tr	*next;
}			t_tr;

/*
**	Sphere
*/

typedef struct s_sp
{
	t_vec		cor;
	t_vec_uc	col;
	float		diameter;
	float		radius;
	struct s_sp	*next;
}			t_sp;

/*
**	Ambient light
*/

typedef struct s_amb_light
{
	float		ratio;
	t_vec_uc	col;
}			t_amb_light;

/*
**	Camera
*/

typedef struct s_image_var
{
	t_vec		u;
	t_vec		v;
	t_vec		w;
	t_vec		tmp;
	t_vec		tmp2;
	t_vec		tmp3;
	t_vec		tmp4;
	float		theta;
	float		half_width;
	float		half_height;
}			t_image_var;

typedef struct s_image_plane
{
	t_vec		upper_left;
	t_vec		horizontal;
	t_vec		vertical;
}			t_image_plane;

typedef struct s_cameraPP
{
	t_image_plane		*image;
	t_vec				cor;
	t_vec				norm;
	float				FOV;
	struct s_cameraPP	*next;
}			t_cameraP;

/*
**	ratio:	the brights ratio values [0.0, 1.0]
*/

typedef struct s_light
{
	t_vec			cor;
	t_vec_uc		col;
	float			ratio;
	struct s_light	*next;
}			t_light;

typedef struct s_task
{
	size_t		X_res;
	size_t		Y_res;
	t_amb_light	Amb_light;
	t_sq		*sq;
	t_pl		*pl;
	t_cy		*cy;
	t_sp		*sp;
	t_tr		*tr;
	t_light		*light;
	t_cameraP	*camera;
	int			curent;
	char		save;
	char		MOVE;
}			t_task;

typedef struct s_pars_vars
{
	char		*line;
	int			fd;
	int			ret;
	int			res;
	int			ambient;
	int			i;
	size_t		line_cnt;
}			t_pars_vars;

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_task	task;
}			t_data;

typedef struct s_hit_sp
{
	float		a;
	float		b;
	float		c;
	float		disc;
	t_vec		test;
	t_vec		oc;
}			t_hit_sp;

typedef struct s_hit_tr
{
	float	den;
	float	t;
	t_vec	i;
	t_vec	AB;
	t_vec	AC;
	t_vec	BC;
	t_vec	norm;
	t_vec	cross_AB_AC;
	t_vec	vec_Q_tr_edge;
	t_vec	testing;
	t_vec	Q;
}		t_hit_tr;

typedef struct s_hit_sq
{
	float	den;
	t_vec	test;
	t_vec	span_a;
	t_vec	span_b;
	t_vec	tmp;
	t_vec	Q;
	t_vec	dis;
	float	t;
	float	abs;
}		t_hit_sq;

typedef struct s_hit_cy
{
	double	vars[7];
	t_vec	vecs[3];
}		t_hit_cy;

typedef struct s_lights
{
	t_light		*li;
	float		diff;
	float		spec;
	float		side;
	int			go;
	t_vec1		max_diff;
	t_vec1		max_spec;
	t_vec1		max_light;
	t_vec		light_vec;
	t_ray		shadow;
	t_ray		ray;
	t_hit		hit;
}		t_lights;

#endif
