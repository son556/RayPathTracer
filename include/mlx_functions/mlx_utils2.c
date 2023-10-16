/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:48 by chanson           #+#    #+#             */
/*   Updated: 2023/04/25 14:25:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_function.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
