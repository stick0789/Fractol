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

static int	is_valid_normal(int ac, char **av)
{
	int	res;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
				|| !ft_strncmp(av[1], "tricorn", 7)))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		res = 1;
	else
		res = 0;
	return (res);
}

static int	is_valid_julia(double re, double im)
{
	int	res;

	if ((re >= -2.0 && re <= 2.0) && (im >= -2.0 && im <= 2.0))
		res = 1;
	else
		res = 0;
	return (res);
}

static void	first_init(int ac, char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	if (is_valid_normal(ac, av) == 1)
		fractal->val_mandel = 2;
	if (!ft_strncmp(av[1], "tricorn", 7))
		fractal->val_mandel = -2;
	if (ac == 4)
	{
		fractal->jul_x = ft_atodbl(av[2]);
		fractal->jul_y = ft_atodbl(av[3]);
	}
}

static void	error_message(int val)
{
	char	*error;

	error = "Please enter one of the following options: \n" \
			"\t./fractol mandelbrot \n" \
			"\t./fractol trindecorn \n" \
			"\t./fractol julia <value_1> <value_2> \n" \
			"For Julia values, you can use any of the following: \n" \
			"\t<value_1> \t <value_2> \n" \
			"\t0.355 \t +0.355i \n" \
			"\t-0.70176 \t +0.3842i \n" \
			"\t0.285 \t +0.01i \n" \
			"\t-0.8 \t +0.156i \n" \
			"\t0.4 \t +0.6i \n" \
			"\t-0.701 \t +0.27015i";
	if (val == 1)
		ft_putstr_fd(error, 2);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (is_valid_normal(ac, av) == 1)
	{
		first_init(ac, av, &fractal);
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			if (is_valid_julia(fractal.jul_x, fractal.jul_y) == 0)
			{
				error_message(1);
				exit(EXIT_FAILURE);
			}
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_conex);
	}
	else
	{
		error_message(1);
		exit(EXIT_FAILURE);
	}
}
