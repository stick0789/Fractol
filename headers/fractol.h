/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:42:30 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/13 22:03:39 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

/*---	Librerias Auxiliares // Auxiliar Libs ---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "libft.h"
#include "../minilibx-linux/mlx.h"

/*---   Tamaño de la Ventana // Window Size ---*/
#define WIDTH	800
#define HEIGHT	800

/*--- Colores Usados // Used Colors ---*/
#define BLACK   0x000000
#define WHITE   0xFFFFFF
#define HELIOTROPE_MAGENTA 0xB41CB9 //(color){180, 28, 185}   [1]
#define ORANGE_RED         0xFE6410 //(color){254, 100, 16}   // #[1]
#define SAFFRON            0xF4CD28 //(color){244, 205, 40}   //  [1]
#define RYB_GREEN          0x5EAF33 //(color){94, 175, 51}    // # [1]
#define SPARTAN_CRIMSON    0xA01F1E //(color){160, 31, 30}    // # [1]
#define DARK_IMPERIAL_BLUE 0x011369 //(color){1, 19, 105}    // # [1]
#define SHOCKING_PINK      0xFF01D7 //(color){255, 1, 215}    // # [3]
#define MIDDLE_YELLOW      0xFFEB00 //(color){255, 235, 0}    // # [3]
#define VIVID_RED          0xFC0019 //(color){252, 0, 25}     // # [3]
#define MALACHITE          0x01FF4F //(color){1, 255, 79}     // # [3]
#define INTERDIMENSIONAL_BLUE 0x5600CC //(color){86, 0, 204}   // # [3]
#define TURQUOISE_BLUE     0x00EDF5 //(color){0, 237, 245}    // # [3]
#define PSYCHEDELIC_PURPLE 0xDF00FF //(color){223, 0, 255}    // # [5]

/*--- Estructura de la Imagen // Image Structure ---*/
typedef struct	s_image
{
	void	*img_ptr; //pointer to an image struct
	char	*pix_ptr; //points to the actual pixel
	int	bpp;	//bit per pixel
	int	endian;
	int	line_len;
}	t_img;	

/*--- Estructura de Fractal // Fractal Structure ---*/
typedef struct	s_fractal
{
	char	*name;
	void	*mlx_conex; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	t_img	img;

	double	escape_value;//hypotenuse
	int	iteration_definition;
}	t_fractal;

/*--- Estructura Numeros Complejos // Complex Numbers Structure ---*/
typedef struct	s_complex
{
	//real para los x imaginarios para y = i
	double	x;
	double	y;
}	t_complex;

/*--- Funciones de Fractales // Fractal Functions ---*/
void    fractal_init(t_fractal *fractal);
void    fractal_render(t_fractal *fractal);

/*--- Acciones-Eventos // Actions-Events --- */
int     key_actions(int keyid, t_fractal *fractal);

/*--- Auxiliares Matematicos // Math Utils ---*/
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex       sum_complex(t_complex z1, t_complex z2);
t_complex       square_complex(t_complex z);
#endif
