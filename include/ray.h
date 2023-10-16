/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:20:15 by chanson           #+#    #+#             */
/*   Updated: 2023/05/15 18:06:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_point3	point;
	t_dir		direction;
	double		albedo;
	double		time;
}	t_ray;

typedef struct s_light
{
	t_point3	point;
	t_color3	color;
	double		ratio;
}	t_light;

t_ray		ray_init(t_point3 point, t_dir direction);
t_point3	ray_at(t_ray ray, double t);
t_light		light_init(t_point3 p, t_color3 c, double ratio);
#endif