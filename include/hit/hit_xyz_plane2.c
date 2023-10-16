/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_xyz_plane2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:45:27 by chanson           #+#    #+#             */
/*   Updated: 2023/05/26 13:52:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	get_xyz_pl_uv(t_obj obj, t_norm *norm, t_ray ray)
{
	double	x;
	double	y;
	double	z;

	x = ray.point.x + norm->root * ray.direction.x;
	y = ray.point.y + norm->root * ray.direction.y;
	z = ray.point.z + norm->root * ray.direction.z;
	if (obj.xyz_pl.xyz == 0)
	{
		norm->u = (x - obj.xyz_pl.x0) / (obj.xyz_pl.x1 - obj.xyz_pl.x0);
		norm->v = (y - obj.xyz_pl.y0) / (obj.xyz_pl.y1 - obj.xyz_pl.y0);
	}
	else if (obj.xyz_pl.xyz == 1)
	{
		norm->u = (x - obj.xyz_pl.x0) / (obj.xyz_pl.x1 - obj.xyz_pl.x0);
		norm->v = (z - obj.xyz_pl.z0) / (obj.xyz_pl.z1 - obj.xyz_pl.z0);
	}
	else
	{
		norm->u = (y - obj.xyz_pl.y0) / (obj.xyz_pl.y1 - obj.xyz_pl.y0);
		norm->v = (z - obj.xyz_pl.z0) / (obj.xyz_pl.z1 - obj.xyz_pl.z0);
	}
}
