/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:42:30 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/15 20:20:14 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

/*---	Librerias Auxiliares // Auxiliar Libs ---*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"

/*---   Tamaño de la Ventana // Window Size ---*/
# define WIDTH	800
# define HEIGHT	800

/*---	Teclas Usadas // Used Keys --- */
# define ESC	65307
# define UP	65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define MINUS	65451
# define PLUS	65453

/*---	Opciones del Mouse // Mouse Options ---*/
# define LEFTCLICK	1
# define RIGHTCLICK	3
# define ZOOMIN		4
# define ZOOMOUT		5

/*--- Colores Usados // Used Colors ---*/
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define HELIOTROPE_MAGENTA 0xB41CB9 //(color){180, 28, 185}   [1]
# define ORANGE_RED         0xFE6410 //(color){254, 100, 16}   // #[1]
# define SAFFRON            0xF4CD28 //(color){244, 205, 40}   //  [1]
# define RYB_GREEN          0x5EAF33 //(color){94, 175, 51}    // # [1]
# define SPARTAN_CRIMSON    0xA01F1E //(color){160, 31, 30}    // # [1]
# define DARK_IMPERIAL_BLUE 0x011369 //(color){1, 19, 105}    // # [1]
# define SHOCKING_PINK      0xFF01D7 //(color){255, 1, 215}    // # [3]
# define MIDDLE_YELLOW      0xFFEB00 //(color){255, 235, 0}    // # [3]
# define VIVID_RED          0xFC0019 //(color){252, 0, 25}     // # [3]
# define MALACHITE          0x01FF4F //(color){1, 255, 79}     // # [3]
# define INTERDIMENSIONAL_BLUE 0x5600CC //(color){86, 0, 204}   // # [3]
# define TURQUOISE_BLUE     0x00EDF5 //(color){0, 237, 245}    // # [3]
# define PSYCHEDELIC_PURPLE 0xDF00FF //(color){223, 0, 255}    // # [5]

/*--- Estructura de la Imagen // Image Structure ---*/
typedef struct s_image
{
	void	*img_ptr; //pointer to an image struct
	char	*pix_ptr; //points to the actual pixel
	int		bpp;	//bit per pixel
	int		endian;
	int		line_len;
}	t_img;	

/*--- Estructura de Fractal // Fractal Structure ---*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_conex; //mlx_init()
	void	*mlx_window;	//mlx_new_window()
	t_img	img;

	double	escape_value;//hypotenuse
	double	move_x;
	double	move_y;
	double	zoom;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	x;
	double	y;
	double	jul_x;
	double	jul_y;
	int		val_mandel;
	int		iteration_definition;
}	t_fractal;

/*--- Estructura Numeros Complejos // Complex Numbers Structure ---*/
typedef struct s_complex
{
	//real para los x imaginarios para y = i
	double	x;
	double	y;
}	t_cmplx;

/*--- Funciones de Fractales // Fractal Functions ---*/
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

/*--- Acciones-Eventos // Actions-Events --- */
int		close_window(t_fractal *fractal);
int		key_actions(int keyid, t_fractal *fractal);
int		mouse_actions(int buttonid, int x, int y, t_fractal *fractal);

/*--- Auxiliares Matematicos // Math Utils ---*/
t_cmplx	sum_complex(t_cmplx z1, t_cmplx z2);
t_cmplx	square_complex(t_cmplx z, int val_mandel);
double	scale(double unscaled_num, double new_min,
			double new_max, double old_max);
double	ft_atodbl(const char *nptr);
#endif
