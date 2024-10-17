#include "long_lib.h"

#define MLX_ERROR	1
#define WIDTH			1920
#define HEIGHT			1080


int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		close(data, 0);
		exit(1);
	}
	return (0);
}

int	main(void)
{
	t_data	data;
	char	*relative_path = "./sprites/test.xpm";
	int		img_width;
	int		img_height;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "My Window");
	data.img.img = mlx_xpm_file_to_image(data.mlx, relative_path, &img_width, &img_height);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.depth, &data.img.line_length, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 16, 16);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	return 0;
}