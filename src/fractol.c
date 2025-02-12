/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:40:21 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/12 20:54:17 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"


//infinite zoom
//able to take coomand line args to select wich fractal render 
//able to take command line args to shape julia .er x y coordinates
//ESC closes the process without leaks - also the click on X 
//
//-----------------------------------
//create the executable to take julia, and mandelbrot
// (./fractol mandelbrot)
// (./fractol julia <real> <i>
int	main(int ac, char **av)
{
	char	*set;
	t_fractal	fractal;
	set = av[1];
	//if the info is right, init the fractol, render the window and keep listening the events
	//else set the error mssg
	if ((ac == 2 && !ft_strncmp(set, "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(set, "julia", 5)))
	{
		fractal.name = av[1];
		//iniciar el fractol
		fractal_init(&fractal);	
		//renderizar la ventana del fractal
		fractal_render(&fractal);
		//leave control to the server (to use the hooks)
		mlx_loop(fractal.mlx_conex);
	}
	else
		ft_putstr_fd("Error, introduce el nombre del conjunto a ejecutar", 2);
}

/*
//compilacion debe ser cc *.c -Lminilibx-linux -lmlx_linux -lX11 -lXext -o fractol
//-Lminilibx-linux -> the path for the minilibx
//-lmxlx_linux  -> the name of the library
//preuba de la formula mandelbrot y matematica para hacer fractol
int	main()
{
	//z el numero complejo que sigue la formula y c el punto dentro del plano 
	t_complex	z;
	t_complex	c;
	int	i;

	z.real = 0;
	z.i = 0;
	i = 0;
	while (i < 42)
	{
		//formula general de mandelbrot: z = z^2 + c
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		//ahora se suma el valor de c 
		z.real += c.real;
		z.i += c.i
		i++;
	}
}*/
