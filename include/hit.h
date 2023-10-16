/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:11 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 14:39:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "vec3.h"
# include "ray.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "mlx_function.h"

typedef int				t_bool;

enum e_objects
{
	SPHERE,
	CYLINDER,
	PLANE,
	XYZ_PLANE,
	CUBE,
	CONE,
	PARABOLOID,
	METAL,
	GLASS,
	PLASTIC,
	LIGHT,
	CHECK_TEXTURE,
	NOISE_TEXTURE,
	IMAGE_TEXTURE
};

typedef struct s_texture
{
	t_data	data;
	int		width;
	int		height;
}	t_texture;

typedef struct s_point2
{
	double	x;
	double	y;
}	t_point2;

typedef struct s_resolution
{
	char		*flag;
	t_point2	point;
}	t_resolution;

typedef struct s_mlx
{
	t_vars			*mlx;
	float			res_ratio;
	t_resolution	res;
	t_data			buffer;
	t_texture		check;
	t_texture		block_c;
	t_texture		block_b;
}	t_mlx;

typedef struct s_aabb
{
	t_vec3	minimum;
	t_vec3	maximum;
}	t_aabb;

typedef struct s_triangle
{
	t_vec3	n1;
	t_vec3	n2;
	t_vec3	n3;
	t_vec3	n_vec;
}	t_tri;

typedef struct s_cube_plane
{
	t_vec3	center;
	t_vec3	n_vec;
	double	length;
	t_vec3	plane_vertex[4];
	t_vec3	color;
}	t_cube_plane;

typedef struct s_cube
{
	t_cube_plane	plane[6];
	double			t_root;
	double			len;
	t_vec3			cube_c;
	t_vec3			n_vec;
	t_vec3			n_vec_2;
}	t_cube;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3	center;
	double	height;
	double	radius;
	t_vec3	n_vec;
	t_vec3	c_c;
	t_vec3	c_h;
}	t_cylinder;

typedef struct s_xyz_pl
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;
	double	z0;
	double	z1;
	double	k;
	int		xyz;
	t_vec3	cen;
	t_vec3	n_vec;
}	t_xyz_pl;

typedef struct s_plane
{
	t_vec3		center;
	t_vec3		n_vec;
	t_color3	color;
}	t_plane;

typedef struct s_cone
{
	t_vec3	c_h;
	double	radius;
	double	height;
	double	c_cos;
	t_vec3	n_vec;
	t_plane	pl;
}	t_cone;

typedef struct s_para
{
	t_vec3		cen;
	t_plane		pl;
	double		len;
	double		r;
	double		len_cc;
}	t_para;

typedef struct s_obj
{
	enum e_objects	type;
	t_cylinder		cylinder;
	t_sphere		sphere;
	t_cube			cube;
	t_cone			cone;
	t_plane			plane;
	t_para			para;
	t_xyz_pl		xyz_pl;
	t_light			light;
	t_color3		color;
	enum e_objects	material;
	enum e_objects	texture;
	double			fuzz;
	double			ref_idx;
	t_aabb			bound_box;
	t_mlx			mlx;
}	t_obj;

typedef struct s_discrim
{
	t_vec3		ac;
	double		a;
	double		b;
	double		c;
	double		discrim;
	double		root;
}	t_discrim;

typedef struct s_bvhnode
{
	int					start;
	int					end;
	int					idx;
	t_aabb				outbox;
	struct s_bvhnode	*left;
	struct s_bvhnode	*right;
	struct s_bvhnode	*up;
}	t_bvhnode;

typedef struct s_bvhtree
{
	t_bvhnode	*head;
	t_bvhnode	*new_point;
	t_bvhnode	*pre_point;
	int			left_right;
}	t_bvhtree;

typedef struct s_img
{
	unsigned char	*data;
	int				width;
	int				height;
	int				bytes_per_scanline;
}	t_img;

typedef struct s_noise
{
	double			u;
	double			v;
	double			w;
	t_vec3			ranfloat[256];
	int				p_x[256];
	int				p_y[256];
	int				p_z[256];
}	t_noise;

typedef struct s_norm
{
	double			root;
	t_vec3			n_vec;
	t_point3		hit;
	double			t_max;
	t_color3		albedo;
	t_light			light;
	t_light			ambi;
	t_light			spec;
	t_color3		background;
	int				front;
	int				depth;
	int				hit_idx;
	enum e_objects	material;
	double			u;
	double			v;
	t_bvhtree		tree;
	t_noise			noise;
	t_img			img;
}	t_norm;

// hit
t_norm		hit_sphere(t_sphere sph, t_ray ray, double t_max);
t_norm		hit_plane(t_plane pln, t_ray ray, double t_max);
t_aabb		sphere_aabb_box(t_sphere sph);

// hit_aabb
int			hit_aabb(t_ray ray, double t_max, double t_min, t_aabb box);
t_aabb		make_aabb_box(t_vec3 minimum, t_vec3 maximum);
t_aabb		make_out_box(t_obj *obj, int start, int end);

// hit_aabb2
t_aabb		make_surrounding_box(t_aabb box1, t_aabb box2);
int			left_right_box(t_aabb box1, t_aabb box2, int axis);
void		sort_obj_by_axis(t_obj *obj, int start, int end, int axis);

// hit_aabb3
t_bvhnode	*make_bvhnode(int start, int end, t_obj *obj);
void		make_bvh_tree(t_obj *obj, int start, int end, t_norm *norm);
int			bvh_hit(t_norm *norm, t_ray ray, t_obj *obj);

// hit_cone
t_norm		hit_cone(t_cone	con, t_ray ray, double t_max);

// hit_cone2
void		complete_cone(t_cone *con, t_vec3 cen, t_vec3 n_vec, t_vec3 rh);
t_aabb		cone_aabb_box(t_cone cone);
void		get_uv(t_norm *norm, t_vec3 point, t_vec3 cen);

// hit_cube
t_norm		hit_cube(t_cube cube, t_ray ray, double t_max, t_color3 *color);

// hit_cube2
t_vec3x3	make_n1_n2_c(t_vec3 n1, t_vec3 n2, t_vec3 cen);
void		complete_cube(t_cube *cube, t_vec3x3 n1_n2_c, double l);

// hit_cube3
t_aabb		cube_aabb_box(t_cube cube);

// hit_cylinder
int			range_in_hit(t_discrim *disc, double t_max);
t_norm		hit_cylinder(t_cylinder cyl, t_ray ray, double t_max);

// hit_cylinder2
t_aabb		cylinder_aabb_box(t_cylinder cyl);

// hit_light_color
t_color3	light_color(t_ray ray, t_obj *obj, t_norm *norm, int n);

// hit_noise
t_color3	check_color(double u, double v, t_vec3 point, t_color3 col);
void		perm_and_ranfloat(int *p_x, int *p_y, int *p_z, t_vec3 *ranfloat);
double		perlin_interp(t_vec3 c[2][2][2], double u, double v, double w);
double		trilinear_interp(t_vec3 c[2][2][2], double u, double v, double w);

// hit_noise2
double		noise(t_norm norm);
t_color3	noise_color(t_norm norm, double scale);

// hit_img
t_color3	img_color(t_norm *norm, t_obj *obj);

// hit_obj
void		complete_sphere(t_sphere *sp, t_vec3 cen, double r);
t_vec3x3	cen_vec_rh_init(t_vec3 cen, t_vec3 vec, t_vec3 rh);
void		complete_cyl(t_cylinder *cyl, t_vec3x3 cen_vec_rh);
void		complete_plane(t_plane *pl, t_vec3 cen, t_vec3 vec);

// hit_paraboloid
t_norm		hit_paraboloid(t_para para, t_ray ray, double t_max);

// hit_paraboloid2
double		paraboloid_r(t_para	para);
void		complete_para(t_para *para, t_vec3 center, t_vec3 move, double len);
t_aabb		paraboloid_aabb_box(t_para para);

// hit_ray
t_norm		find_hit_function(t_ray ray, t_obj obj, double t_max);
int			shade(t_norm norm, t_obj *obj, int n, int m);
int			front_or_back(t_ray ray, t_norm norm);
t_ray		diffuse_ray(t_norm norm, t_ray ray);
t_ray		specular_ray(t_norm norm, t_ray ray, double fuzz);

// hit_ray2
t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n);//test
int			obj_arr_hit(t_obj *obj, t_ray ray, t_norm *norm, int n);
t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n);

// hit_ray3
t_ray		refract_ray(t_norm norm, t_ray ray, double ref_idx);

// hit_xyz_plane
void		complete_xyz_pl(t_xyz_pl *xyz_pl, t_vec3 cen, double len, int xyz);
t_norm		hit_xyz_pl(t_ray ray, t_xyz_pl pl, double t_max);

// hit_xyz_plane2
void		get_xyz_pl_uv(t_obj obj, t_norm *norm, t_ray ray);

// test
void		display_cone(t_cone con);
void		display_vec3(t_vec3 vec);
void		display_vec3x3(t_vec3x3 vec);
#endif