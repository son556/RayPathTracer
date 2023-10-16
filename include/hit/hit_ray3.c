/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:23:20 by chanson           #+#    #+#             */
/*   Updated: 2023/05/25 21:10:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static double	reflectance(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

static t_vec3	refract_dir(t_vec3 ray_dir, t_vec3 n_vec, double ref_idx)
{
	double		cos_theta;
	t_vec3		perp;
	t_vec3		parallel;
	t_vec3		dir;

	cos_theta = fmin(dot_vec3(mul_vec3(ray_dir, -1), n_vec), 1.0);
	perp = add_vec3(ray_dir, mul_vec3(n_vec, cos_theta));
	perp = mul_vec3(perp, ref_idx);
	parallel = mul_vec3(n_vec, -1 * sqrt(ft_abs(1 - \
		ft_pow(len_vec3(perp)))));
	dir = add_vec3(perp, parallel);
	return (dir);
}

t_ray	refract_ray(t_norm norm, t_ray ray, double ref_idx)
{
	t_ray		new_ray;
	double		sin_theta;
	double		cos_theta;

	new_ray.point = norm.hit;
	if (norm.front == 1)
		ref_idx = 1.0 / ref_idx;
	cos_theta = fmin(-dot_vec3(ray.direction, norm.n_vec), 1.0);
	sin_theta = sqrt(1.0 - ft_pow(cos_theta));
	if (sin_theta * ref_idx > 1.0)
		return (specular_ray(norm, ray, 0.0));
	if (reflectance(cos_theta, ref_idx) > random_0_to_1())
		return (specular_ray(norm, ray, 0.0));
	new_ray.direction = refract_dir(ray.direction, norm.n_vec, ref_idx);
	new_ray.direction = normalize_vec3(new_ray.direction);
	return (new_ray);
}
