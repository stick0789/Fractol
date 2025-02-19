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

double	scale(double unscaled_num, double new_min,
		double new_max, double old_max)
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
	while (*nptr == 43 || *nptr == 45)
		if (*nptr++ == 45)
			sign *= -1;
	while (*nptr != '.' && *nptr)
		int_part = (*nptr++ - '0') + (int_part * 10);
	if (*nptr == '.')
		nptr++;
	while (*nptr)
	{
		pow /= 10;
		fract_part = fract_part + (*nptr++ - '0') * pow;
	}
	return ((int_part + fract_part) * sign);
}

t_cmplx	sum_complex(t_cmplx z1, t_cmplx z2)
{
	t_cmplx	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_cmplx	square_complex(t_cmplx z, int val_mandel)
{
	t_cmplx	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = val_mandel * z.x * z.y;
	return (result);
}
