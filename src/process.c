/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:02:10 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/15 20:32:40 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

static void	mandel_julia(t_cmplx *z, t_cmplx *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->jul_x;
		c->y = fractal->jul_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_cmplx	z;
	t_cmplx	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	z.x = fractal->x + fractal->move_x;
	z.y = fractal->y + fractal->move_y;
	mandel_julia(&z, &c, fractal);
	while (i < fractal->iteration_definition)
	{
		z = sum_complex(square_complex(z, fractal->val_mandel), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = scale(i, BLACK, WHITE, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		fractal->y = scale(y, fractal->min_im, fractal->max_im, HEIGHT);
		x = -1;
		while (++x < WIDTH)
		{
			fractal->x = scale(x, fractal->min_re, fractal->max_re, WIDTH);
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_conex,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
