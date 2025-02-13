/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:14:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/13 22:06:45 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*key press action int (*f)(int keycode, void *param) */
int	key_actions(int keyid, t_fractal *fractal)
{
	printf("keyId Presionada: %d\n", keyid);
	if (keyid == 65307)
	{
		mlx_destroy_window(fractal->mlx_conex, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_conex);
		free(fractal->mlx_conex);
		return (0);
	}	
	return (0);
}
/*mouse action int (*f)(int button, int x, int y, void *param) */
/*
int	mouse_actions()()
{

}
*/
/*click on x to close int (*f)(void *param) */
/*
int	close_window()()
{
	
}
*/
