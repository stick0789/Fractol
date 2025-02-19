/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:41:22 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/18 18:41:24 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static	void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4.0;
	fractal->iteration_definition = 30;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->zoom = 1.0;
}

static	void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_actions, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_actions, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_window, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_conex = mlx_init();
	if (fractal->mlx_conex == NULL)
		return ;
	fractal->mlx_window = mlx_new_window(fractal->mlx_conex,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_conex);
		free(fractal->mlx_conex);
		return ;
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_conex, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_conex);
		free(fractal->mlx_conex);
		return ;
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
