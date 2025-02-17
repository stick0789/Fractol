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

/*
 * Procesos a ejecutar
 * Init
 * 	mlx
 * 	listening events
 * 	hooks data
 */

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4.0;
	fractal->iteration_definition = 42;
	fractal->move_x = 0.0;
	fractal->move_y = 0.0;
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	/*for the keyboard */
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_actions, fractal);
	/*for the mouse */
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_actions, fractal);
	/*for close with the x in the window */
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_window, fractal);
}

/* put a pixel in the image buffer */
void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pix_ptr + offset) = color;
}

void	fractal_init(t_fractal *fractal)
{
	//inicializacion de la conexion;
	fractal->mlx_conex = mlx_init();
	if (fractal->mlx_conex == NULL)
		return ; //malloc error
	//inicializacion de la ventana
	fractal->mlx_window = mlx_new_window(fractal->mlx_conex, 
					WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_conex);
		free(fractal->mlx_conex);
		return ; //malloc error
	}
	//inicializacion de la imagen
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_conex, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_conex);
		free(fractal->mlx_conex);
		return ;//malloc error
	}
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len,
			&fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
/*
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	//pixel coordenate to the fix mandelbrot set
	c.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->move_x;
	c.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->move_y;

	//how many times iterate z^2 + c to check if the point escaped
	while (i < fractal->iteration_definition)
	{
		//z = z^2 + c 
		z = sum_complex(square_complex(z), c);
		
		//if the value escaped 
		//if the hypotenuse > 2 is becase the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}*/
/* prubeas */
void	handle_pixel(int x, int y,   t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	//pixel coordenate to the fix mandelbrot set
	//c.x = (map(x, fractal->min_re, fractal->max_re, 0, WIDTH) * fractal->zoom) + fractal->move_x;
	//c.y = (map(y, fractal->max_im, fractal->min_im, 0, HEIGHT) * fractal->zoom) + fractal->move_y;
	//c.x = (map(x, fractal->min_re, fractal->max_re, 0, WIDTH)) + fractal->move_x;;
	//c.y = (map(y, fractal->max_im, fractal->min_im, 0, HEIGHT)) + fractal->move_y;
	c.x = fractal->x + fractal->move_x;
	c.y = fractal->y + fractal->move_y; 

	//how many times iterate z^2 + c to check if the point escaped
	while (i < fractal->iteration_definition)
	{
		//z = z^2 + c 
		z = sum_complex(square_complex(z), c);
		
		//if the value escaped 
		//if the hypotenuse > 2 is becase the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}
/* funciona a medias */
/*
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	//pixel coordenate to the fix mandelbrot set
	//c.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->move_x;
	//c.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->move_y;
	c.x = (map(x, fractal->min_re, fractal->max_re, 0, WIDTH) * fractal->zoom) + fractal->move_x;
	c.y = (map(y, fractal->max_im, fractal->min_im, 0, HEIGHT) * fractal->zoom) + fractal->move_y;
	//printf("Posición del pixel x = %d, y = %d\n", x, y);

	//how many times iterate z^2 + c to check if the point escaped
	while (i < fractal->iteration_definition)
	{
		//z = z^2 + c 
		z = sum_complex(square_complex(z), c);
		
		//if the value escaped 
		//if the hypotenuse > 2 is becase the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	double	complex_x;
	double	complex_y;

	y = -1;
	while (++y < HEIGHT)
	{
		//modificado
		fractal->y = scale(y, fractal->min_im, fractal->max_im, HEIGHT);
		//complex_y = map(y, 0, HEIGHT, fractal->min_im, fractal->max_im);
		x = -1;
		while (++x < WIDTH)
		{
			//modificado
			fractal->x = scale(x, fractal->min_re, fractal->max_re, WIDTH);
			//complex_x = map(x, 0, WIDTH, fractal->min_re, fractal->max_re);
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_conex,
				fractal->mlx_window,
				fractal->img.img_ptr,
				0, 0);
}
