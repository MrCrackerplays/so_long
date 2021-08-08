#include <mlx.h>
// #include "../mlx_linux/mlx.h"
#include <stdio.h>
#include "stdlib.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	if (keycode || vars)
	{
		;
	}
	return (keycode);
}

int	close(int keycode, t_vars *vars)
{
	printf("sluiten%i\n", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	if (keycode || vars)
	{
		;
	}
	return (keycode);
}

int	main(void)
{
	t_vars	vars;
	void	*img;
	void	*imge;
	char	*path = "./spritesheet.xpm";
	int		img_width;
	int		img_height;
	int		imge_width;
	int		imge_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	img = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
	imge = mlx_xpm_file_to_image(vars.mlx, "./MasterSimple.xpm", &imge_width, &imge_height);
	if (img == NULL)
		printf("nullie2\n");
	else
		mlx_put_image_to_window(vars.mlx, vars.win, imge, 0, 0);
	if (img == NULL)
		printf("nullie1\n");
	else
	{
		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
		mlx_put_image_to_window(vars.mlx, vars.win, img, img_width, 100);
	}
	mlx_loop(vars.mlx);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }