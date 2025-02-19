/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:14:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/15 20:19:32 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_conex, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_conex);
	free(fractal->mlx_conex);
	exit(EXIT_SUCCESS);
}

int	key_actions(int keyid, t_fractal *fractal)
{
	if (keyid == ESC)
		close_window(fractal);
	else if (keyid == UP)
		fractal->move_y -= (0.1 * fractal->zoom);
	else if (keyid == DOWN)
		fractal->move_y += (0.1 * fractal->zoom);
	else if (keyid == LEFT)
		fractal->move_x += (0.1 * fractal->zoom);
	else if (keyid == RIGHT)
		fractal->move_x -= (0.1 * fractal->zoom);
	else if (keyid == MINUS)
		fractal->iteration_definition += 10;
	else if (keyid == PLUS)
		fractal->iteration_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	range_re = (fractal->max_re - fractal->min_re);
	range_im = (fractal->max_im - fractal->min_im);
	mouse_re = (double)x / WIDTH;
	mouse_im = (double)y / HEIGHT;
	if (buttonid == ZOOMIN)
	{
		fractal->max_re += (range_re * 0.95 - range_re) * (1 - mouse_re);
		fractal->min_re -= (range_re * 0.95 - range_re) * mouse_re;
		fractal->max_im += (range_im * 0.95 - range_im) * (1 - mouse_im);
		fractal->min_im -= (range_im * 0.95 - range_im) * mouse_im;
	}
	else if (buttonid == ZOOMOUT)
	{
		fractal->max_re += (range_re / 0.95 - range_re) * (1 - mouse_re);
		fractal->min_re -= (range_re / 0.95 - range_re) * mouse_re;
		fractal->max_im += (range_im / 0.95 - range_im) * (1 - mouse_im);
		fractal->min_im -= (range_im / 0.95 - range_im) * mouse_im;
	}
	fractal_render(fractal);
	return (0);
}
