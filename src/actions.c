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
#include <math.h>
/*click on x or pres ESC to close int (*f)(void *param) */
int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_conex, fractal->img.img_ptr);	
	mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_conex);
	free(fractal->mlx_conex);
	exit(EXIT_SUCCESS);
}

/*key press action int (*f)(int keycode, void *param) */
int	key_actions(int keyid, t_fractal *fractal)
{
	printf("keyId Presionada: %d\n", keyid);
	if (keyid == ESC)
		close_window(fractal);
	else if (keyid == UP)
		fractal->move_y -= (0.1 * fractal->zoom);
	else if (keyid == DOWN)
		fractal->move_y += (0.1* fractal->zoom);
	else if (keyid == LEFT)
		fractal->move_x += (0.1* fractal->zoom);
	else if (keyid == RIGHT)
		fractal->move_x -= (0.1* fractal->zoom);
	else if (keyid == MINUS)
		fractal->iteration_definition += 10;
	else if (keyid == PLUS)
		fractal->iteration_definition -= 10;
	fractal_render(fractal);
	return (0);
}

/*mouse action int (*f)(int button, int x, int y, void *param) */
/*
int	mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	//mlx_mouse_get_pos(fractal->mlx_conex, fractal->mlx_window, &mouse_x, &mouse_y);
	if (buttonid == ZOOMIN)
		fractal->zoom *= 0.90;
	else if (buttonid == ZOOMOUT)
		fractal->zoom *= 1.1;
	printf("MouseId options: %d\n", buttonid);
	printf("Posición del ratón: x = %d, y = %d\n", x, y);
	//printf("Coordenadas complejas: Re = %f, Im = %f\n", mouse_re, mouse_im);
	//printf("Rango de la ventana: Re = %f, Im = %f\n", range_re, range_im);
	fractal_render(fractal);
	return (0);
}
*/
/* pruebas */
/*aqui funciona algo
int	mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	//mlx_mouse_get_pos(fractal->mlx_conex, fractal->mlx_window, &mouse_x, &mouse_y);
	if (buttonid == ZOOMIN)
		zoom_factor = 0.90;
	else if (buttonid == ZOOMOUT)
		zoom_factor = 1.1;
	else
		return (0);
	//Anadido
	//mouse_re = map(x, 0, WIDTH, fractal->min_re, fractal->max_re);
    	mouse_re = map(x, -2, +2, 0, WIDTH);
	//mouse_im = map(y, 0, HEIGHT, fractal->min_re, fractal->max_re);
    	mouse_im = map(y, +2, -2, 0, HEIGHT);
    	// Calcular el nuevo rango después del zoom
	double range_re = (fractal->max_re - fractal->min_re) * zoom_factor;
	double range_im = (fractal->max_im - fractal->min_im) * zoom_factor;
	fractal->min_re = mouse_re - (mouse_re - fractal->min_re) * zoom_factor;
	fractal->max_re = fractal->min_re + range_re;
	fractal->min_im = mouse_im - (mouse_im - fractal->min_im) * zoom_factor;
	fractal->max_im = fractal->min_im + range_im;
	printf("MouseId options: %d\n", buttonid);
	printf("Posición del ratón: x = %d, y = %d\n", x, y);
	printf("Coordenadas complejas: Re = %f, Im = %f\n", mouse_re, mouse_im);
	printf("Rango de la ventana: Re = %f -> %f | Im = %f -> %f\n", 
				fractal->min_re, fractal->max_re,
				fractal->min_im, fractal->max_im);
	//printf("Rango de la ventana: Re = %f, Im = %f\n", range_re, range_im);
	fractal_render(fractal);
	return (0);
}*/
/*mejoras */
/*
void	zooming(int key, double x, double y, t_fractal *f)
{
	double	i;
	double	j;

	i = f->lim.xmax - f->lim.xmin;
	j = f->lim.ymax - f->lim.ymin;
	if (key == ZOOM_IN)
	{
		f->lim.xmax += (i * ZOOM - i) * (1 - x);
		f->lim.xmin -= (i * ZOOM - i) * x;
		f->lim.ymin -= (j * ZOOM - j) * y;
		f->lim.ymax += (j * ZOOM - j) * (1 - y);
	}
	if (key == ZOOM_OUT)
	{
		f->lim.xmin -= (i / ZOOM - i) * x;
		f->lim.xmax += (i / ZOOM - i) * (1 - x);
		f->lim.ymin -= (j / ZOOM - j) * y;
		f->lim.ymax += (j / ZOOM - j) * (1 - y);
	}
}*/
int	mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	//calcular los rangos 
	range_re = (fractal->max_re - fractal->min_re);
	range_im = (fractal->max_im - fractal->min_im);
	//Calcular coordenas del mouse a porporciones relativas de 0 a 1;
	mouse_re = (double)x / WIDTH;
	mouse_im = (double)y / HEIGHT;
	//mlx_mouse_get_pos(fractal->mlx_conex, fractal->mlx_window, &mouse_x, &mouse_y);
	if (buttonid == ZOOMIN)
	{
		fractal->max_re += (range_re * 0.90 - range_re) * (1 - mouse_re);
		fractal->min_re -= (range_re * 0.90 - range_re) * mouse_re;
		fractal->max_im += (range_im * 0.90 - range_im) * (1 - mouse_im);
		fractal->min_im -= (range_im * 0.90 - range_im) * mouse_im;
	}
	else if (buttonid == ZOOMOUT)
	{
		fractal->max_re += (range_re / 0.90 - range_re) * (1 - mouse_re);
		fractal->min_re -= (range_re / 0.90 - range_re) * mouse_re;
		fractal->max_im += (range_im / 0.90 - range_im) * (1 - mouse_im);
		fractal->min_im -= (range_im / 0.90 - range_im) * mouse_im;
	}
	else
		return (0);
	printf("MouseId options: %d\n", buttonid);
	printf("Posición del ratón: x = %d, y = %d\n", x, y);
	printf("Coordenadas complejas: Re = %f, Im = %f\n", mouse_re, mouse_im);
	printf("Rango de la ventana: Re = %f -> %f | Im = %f -> %f\n", 
				fractal->min_re, fractal->max_re,
				fractal->min_im, fractal->max_im);
	//printf("Rango de la ventana: Re = %f, Im = %f\n", range_re, range_im);
	fractal_render(fractal);
	return (0);
}

/*funciona a medias */
/*
int	mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	//mlx_mouse_get_pos(fractal->mlx_conex, fractal->mlx_window, &mouse_x, &mouse_y);
	if (buttonid == ZOOMIN)
		fractal->zoom *= 0.90;
	else if (buttonid == ZOOMOUT)
		fractal->zoom *= 1.1;
	//Anadido
	//mouse_re = map(x, 0, WIDTH, fractal->min_re, fractal->max_re);
    	mouse_re = map(x, -2, +2, 0, WIDTH);
	//mouse_im = map(y, 0, HEIGHT, fractal->min_re, fractal->max_re);
    	mouse_im = map(y, +2, -2, 0, HEIGHT);
    	// Calcular el nuevo rango después del zoom
	double range_re = (fractal->max_re - fractal->min_re) * fractal->zoom;
	double range_im = (fractal->max_im - fractal->min_im) * fractal->zoom;
	fractal->min_re = mouse_re - (mouse_re - fractal->min_re) * fractal->zoom;
	fractal->max_re = fractal->min_re + range_re;
	fractal->min_im = mouse_im - (mouse_im - fractal->min_im) * fractal->zoom;
	fractal->max_im = fractal->min_im + range_im;
	printf("MouseId options: %d\n", buttonid);
	printf("Posición del ratón: x = %d, y = %d\n", x, y);
	printf("Coordenadas complejas: Re = %f, Im = %f\n", mouse_re, mouse_im);
	printf("Rango de la ventana: Re = %f, Im = %f\n", range_re, range_im);
	fractal_render(fractal);
	return (0);
}
*/
/*
int mouse_actions(int buttonid, int x, int y, t_fractal *fractal)
{
	double mouse_re, mouse_im;
	double zoom_factor;

	if (buttonid == ZOOMIN)
		zoom_factor = 0.90;
	else if (buttonid == ZOOMOUT)
		zoom_factor = 1.1;
	else
		return (0);

    	// Convertir las coordenadas del ratón a coordenadas del plano complejo
    	//mouse_re = map(x, 0, WIDTH, fractal->min_re, fractal->max_re);
    	mouse_re = map(0, -2, +2, 0, WIDTH);
    	//mouse_im = map(y, 0, HEIGHT, fractal->min_re, fractal->max_re);
    	mouse_im = map(0, +2, -2, 0, HEIGHT);

	// Calcular el nuevo rango después del zoom
	double range_re = (fractal->max_re - fractal->min_re) * zoom_factor;
	double range_im = (fractal->max_im - fractal->min_im) * zoom_factor;
	
	//range_re = map(range_re, -2, +2, 0, WIDTH);
	//range_im = map(range_im, +2, -2, 0, HEIGHT);

	fractal->min_re = mouse_re - (mouse_re - fractal->min_re) * zoom_factor;
	fractal->max_re = fractal->min_re + range_re;
	fractal->min_im = mouse_im - (mouse_im - fractal->min_im) * zoom_factor;
	fractal->max_im = fractal->min_im + range_im;


	printf("MouseId options: %d\n", buttonid);
	printf("Posición del ratón: x = %d, y = %d\n", x, y);
	printf("Coordenadas complejas: Re = %f, Im = %f\n", mouse_re, mouse_im);
	printf("Rango de la ventana: Re = %f, Im = %f\n", range_re, range_im);

	fractal_render(fractal);
	return (0);
}
*/

