/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cube3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:00:19 by chanson           #+#    #+#             */
/*   Updated: 2023/05/17 21:04:02 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_aabb	cube_aabb_box(t_cube cube)
{
	t_aabb	bound_box;
	double	r;

	r = sqrt(ft_pow(cube.len) * 2);
	bound_box.minimum = sub_vec3(cube.cube_c, vec3init(r, r, r));
	bound_box.maximum = add_vec3(cube.cube_c, vec3init(r, r, r));
	return (bound_box);
}
