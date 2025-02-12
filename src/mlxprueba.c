#include "mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	size_x;
	int	size_y;
	char	*title;

	size_x = 500;
	size_y = 500;
	title = "Fractol - Chingon"
	//establecer la conexion con la libreria
	mlx_ptr = mlx_init();
	//para abrir una nueva ventana
	//mlx_new_window(1arg: tipo void: mlx_ptr, 2arg type int: tamano x, 3arg tamano y, 4arg type char *:titulo de la ventana);
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
	//una funcion esencial mlx_loop(mlx_ptr);
	mlx_loop(mlx_ptr);
	//funcion para dibujar dentro de la ventana
}
