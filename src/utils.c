/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:11:56 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/13 18:55:30 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

double	scale(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / old_max + new_min);
}

double	ft_atodbl(const char *nptr)
{
	long	int_part;
	double	fract_part;
	double	pow;
	long	sign;

	int_part = 0;
	fract_part = 0;
	sign = 1;
	pow = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
		sign *= -1;
	if (*nptr == 43 || *nptr == 45)
		nptr++;
	while (*nptr != '.' && *nptr)
	{
		int_part = (*nptr - '0') + (int_part * 10);
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	while (*nptr)
	{
		pow /= 10;
		fract_part = fract_part + (*nptr - '0') * pow;
		nptr++;
	}
	return ((int_part + fract_part) * sign);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
