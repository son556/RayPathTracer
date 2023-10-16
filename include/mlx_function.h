/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:20:41 by chanson           #+#    #+#             */
/*   Updated: 2023/04/18 15:25:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCTION_H
# define MLX_FUNCTION_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		exit_hook(void);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif