// #include <mlx.h>
#include "mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	if (mlx)
	{
		;
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	if (mlx_win)
	{
		;
	}
}
