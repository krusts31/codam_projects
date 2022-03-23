/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   miniRT_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrust@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:21:05 by alkrusts      #+#    #+#                 */
/*   Updated: 2021/04/30 12:21:05 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H
# include "../../libs/minilibx/mlx.h"
# include "varibles_bonus.h"

/*
**	CAMERA FUNCTIONS 
*/

t_ray			get_ray(float u, float v, t_cameraP *cam);
t_camera		*new_camera(void);
int				init_col_var(t_col_var **var);
t_image_plane	*ft_init_image_plane(void);
t_image_plane	*new_image_plane(float FOV, float portion, t_cameraP *camera);
t_image_var		*ft_init_image(void);
void			*ft_free_image(t_image_plane **plane);
void			*ft_image_error(t_image_var **var, t_image_plane **plane);
int				i_con2(t_image_plane **new, t_image_var **var, t_cameraP *c);
int				free_draw(t_draw **draw);
t_draw			init_draw(int xs, int ys, int ns);

/*
**		RAY FUNTIONS
*/

t_vec			point_at_param(t_ray ray, float num);
t_ray			new_ray(t_vec vec1, t_vec vec2);

/*
**		PIXEL FUNCTIONS
*/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*
**		DRAW SQUARE
*/

/*
**		TRIANGLE
*/

/*
**		MAKE HIT
*/

t_vec1			hitable_list(t_ray ray, t_task *task);

/*
**		HEXAGON
*/

int				ft_hex1(t_data *img, int x, int y, int size);
int				ft_hex(t_data *img, int x, int y, int size);
int				ft_hex3(t_data *img, int x, int y, int size);
int				ft_hex2(t_data *img, int x, int y, int size);

/*
**		SPHERE
*/

int				hit_sp(t_ray ray, t_hit *hit, t_sp sp);
int				hit_sp_loop(t_ray ray, t_hit *hit, t_task task);
t_vec1			sp_light(t_lights li, t_task task);

char			c_sp(t_hit *hit, t_hit_sp hit_sp, t_sp sp, t_ray ray);
char			c_sp_sh(t_hit_sp **hit_sp, t_hit *hit, t_ray ray, t_sp *sp);

/*
**	SPECULAR LIGHT
*/

t_vec			*rand_in_unit_sphere(void);

/*
**		COLORS
*/

unsigned int	create_trgb(t_vec_i i);
int				get_b(int trgb);
int				get_g(int trgb);
int				get_r(int trgb);
int				get_t(int trgb);
void			get_color(t_task *task, t_draw *draw, int i, int j);
t_vec			*color(t_ray **ray, t_task *task, int depth);

/*
**		hit_list functions
*/

char			free_task(t_task *task);
int				is_hit(t_col_var **var, t_ray **ray, int *iter);
t_vec			*c_e(t_col_var **var, t_vec **h, int *iter, t_draw **ray);
int				free_task_draw(t_task **task, t_draw **draw, int ret);
int				scatter(t_hit **rec, t_ray **scatt, t_vec **att);
int				hooks(int key, t_data *d);
void			move_camera(t_cameraP **tmp_camera, char MOVE);
void			init_mlx(t_data *d, t_task *t);
int				ft_camera_size(t_cameraP *cam);
int				draw_back_ground(void *img, t_task *task);
int				close_red(t_data *d);
void			save_bmp(t_data *data);
void			resize_screen(t_data *data);

/*
**	HIT TRIANGLE FUNCTIONS
*/

int				hit_tr(t_ray ray, t_hit *hit, t_tr tr);
t_vec1			tr_li(t_lights lights, t_task task, t_tr tr);

/*
**	HIT SQUARE
*/

int				hit_sq(t_ray ray, t_hit *hit, t_sq sq);
/*
**	HIT CYLINDER
*/

int				hit_cy(t_ray ray, t_hit *hit, t_cy cy);
t_vec1			cy_light(t_lights lights, t_task task);
int				cy_shade(t_ray shadow, t_task task, t_cy *curent, t_hit hit);

/*
**		LIGHT FUNCTOIONS
*/

t_sc			*diff_light(t_hit hit, t_light li, float coef);
t_vec1			light_Amb(t_hit hit, t_task task);
t_sc			*specular(float spec, t_task *task);
t_vec1			finito(t_hit *hit, t_task task);
int				shade(t_ray shadow, t_task task, t_hit hit);

/*
**	UTILS FOR LIGHT CALCULATIONS
*/

size_t			light_obj_count(t_light *li);
t_vec1			free_l(t_sc *specular, t_sc *diffuse);
t_vec			specular_lighting(t_vec norm, t_vec light_vec);
float			light_coef(t_lights *li, t_hit *hit, t_ray ray, t_task *t);
int				add_sc(t_sc **lst, t_sc *node);

/*
**	SQ lighting
*/

t_vec1			sq_light(t_lights li, t_task task);
int				sq_shade(t_ray shadow, t_task task, t_sq *curent, t_hit hit);

/*
**		LIGHTING TRIANGLE
*/

t_vec1			tr_light(t_lights li, t_task task);
int				tr_shade(t_ray shadow, t_task task, t_tr *curent, t_hit hit);
int				hit_cy_sh(t_ray ray, t_hit hit, t_cy cy);

/*
**	NORMING AND FIXING EDGE CASES
**	IF THE VECTOR CONTAINS 0 IT WILL BE CHANGED TO 0.001 
**	
*/

int				norm_round(t_vec *norm, int round);

/*
**	DEBUG
*/

void			print_debug_tr(t_task *task, t_tr *tr);
void			print_debug(t_task *task);

/*
**	CAMERA BONUS
*/

void			move_camera_z(t_data *d, int move);
void			move_camera_y(t_data *d, int move);
void			move_camera_x(t_data *d, int move);

/*
**	PLANE FUNCTIONS
*/

t_vec1			pl_light(t_lights lights, t_task task);
int				hit_pl(t_ray ray, t_hit *hit, t_pl pl);
int				pl_shade(t_ray shadow, t_pl *curent, t_task task, t_hit hit);

/*
**	SPHEAR FUNCTUIONS
*/

float			max_value_arr(float *arr, size_t index);

/*
**	Vectors operatoins
*/

t_vec			vec_minus_vec_uc(t_vec v1, t_vec_uc v2);
t_vec			vec_minus_vec(t_vec v1, t_vec v2);
float			length_of_vector(t_vec s);
float			dot_product(t_vec v1, t_vec v2);
t_vec			cross_product(t_vec v1, t_vec v2);
t_vec			vec_uc_div_num(t_vec v1, float num);
t_vec			sum_of_light(t_vec *ptr, size_t index);
t_vec			vec_div_num(t_vec v1, float num);
t_vec			vec_times_num(t_vec v1, float num);
t_vec			vec_uc_div_vec(t_vec v1, t_vec_uc v2);
t_vec			unit_vec(t_vec v);
float			length_of_vector_pow2(t_vec *self);
t_vec			vec_uc_times_num(t_vec_uc v1, float num);
t_vec			vec_plus_vec(t_vec v1, t_vec v2);
t_vec1			vec_plus_vec_3(t_vec1 v1, t_vec1 v2);
t_vec1			vec_times_num_4(t_vec_uc v1, t_vec1 v2);
t_vec1			vec_times_vec_3(t_vec1 v1, t_vec1 v2);
t_vec1			vec_uc_times_num_3(t_vec_uc v1, float num);
t_vec1			vec_div_vec_uc(t_vec1 v1, t_vec_uc v2);
t_vec1			vec_div_num_3(t_vec1 v1, float num);
t_vec1			vec_times_num_2(t_vec1 v1, float num);

/*
**	VECTOR/ARRAY MAIPULATIONS
*/

t_vec1			cap(t_vec1 v, float min, float max);
t_vec_i			cap_i(t_vec1 v, float min, float max);
t_vec1			max_values_lst(t_sc *lst);
t_vec1			max_value_of_2_vec(t_vec1 v1, t_vec1 v2);
float			max_from_float_arr(float *ptr, size_t cnt);

/*
**	UTILES
*/

#endif
