/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:14:08 by chanson           #+#    #+#             */
/*   Updated: 2023/05/31 13:48:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# define PI 3.1415926535897

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_color3;
typedef struct s_vec3	t_dir;
typedef struct s_vec3	t_point3;
typedef struct s_vec3x3	t_vec3x3;
typedef struct s_vec3x3	t_rot;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_inverse_factor
{
	double	det_a;
	double	c_11;
	double	c_12;
	double	c_13;
	double	c_21;
	double	c_22;
	double	c_23;
	double	c_31;
	double	c_32;
	double	c_33;
}	t_inverse_factor;

struct s_vec3x3
{
	t_vec3	v_x;
	t_vec3	v_y;
	t_vec3	v_z;
};

//vec_utils1
t_vec3		vec3init(double x, double y, double z);
t_vec3		add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		mul_vec3(t_vec3 v1, double t);
t_vec3		div_vec3(t_vec3 v1, double t);

//vec_utils2
double		dot_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		cross_vec3(t_vec3 v1, t_vec3 v2);
double		len_vec3(t_vec3 v1);
t_vec3		normalize_vec3(t_vec3 v1);
t_vec3x3	mul_vec3x3(t_vec3x3 v1, t_vec3x3 v2);

//vec_utils3
double		dotself_vec3(t_vec3 v);
t_vec3x3	vec3x3init(t_vec3 v_x, t_vec3 v_y, t_vec3 v_z);
t_vec3		vec3x3_x_vec3(t_vec3x3 vec3x3, t_vec3 vec);
t_vec3x3	transpose_vec3x3(t_vec3x3 vec3x3);
double		ft_abs(double num);

//vec_utils4
t_rot		rotate_vec(double t1, double t2, double t3);
double		ft_pow(double a);
t_vec3		point_symemtry(t_vec3 target, t_vec3 std);
t_vec3		add_vec3_num(t_vec3 vec, double num);
double		ft_min(double d1, double d2);

//vec_utils5
t_vec3x3	vec3x3_x_double(t_vec3x3 vec, double t);
t_vec3x3	inverse_vec3x3(t_vec3x3 vec);
double		getradian(int num);
double		ft_minmax(double val, double t_min, double t_max);

//vec_utils6
double		random_0_to_1(void);
double		random_min_max(double min, double max);
t_vec3		vec3_rand(void);
t_vec3		minmax_vec3(t_vec3 vec, double min, double max);
t_vec3		random_minmax_vec3(double min, double max);

//vec_utils7
int			random_int(int min, int max);
t_vec3		vec3_x_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3		random_in_unit_sphere(void);
t_vec3		rotate_xy_vec3(t_vec3 vec3);
int			argb_(int a, int r, int g, int b);
#endif