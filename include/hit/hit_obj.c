/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:07:40 by chanson           #+#    #+#             */
/*   Updated: 2023/05/11 20:35:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	complete_sphere(t_sphere *sp, t_vec3 cen, double r)
{
	sp->center = cen;
	sp->radius = r;
}

t_vec3x3	cen_vec_rh_init(t_vec3 cen, t_vec3 vec, t_vec3 rh)
{
	t_vec3x3	cen_vec_rh;

	cen_vec_rh.v_x = cen;
	cen_vec_rh.v_y = normalize_vec3(vec);
	cen_vec_rh.v_z = rh;
	return (cen_vec_rh);
}

void	complete_cyl(t_cylinder *cyl, t_vec3x3 cen_vec_rh)
{
	cyl->center = cen_vec_rh.v_x;
	cyl->n_vec = cen_vec_rh.v_y;
	cyl->radius = cen_vec_rh.v_z.x;
	cyl->height = cen_vec_rh.v_z.y;
	cyl->c_h = add_vec3(cyl->center, mul_vec3(cyl->n_vec, cyl->height * 0.5));
	cyl->c_c = add_vec3(cyl->center, mul_vec3(cyl->n_vec, cyl->height * -0.5));
}

void	complete_plane(t_plane *pl, t_vec3 cen, t_vec3 vec)
{
	pl->center = cen;
	pl->n_vec = vec;
}
