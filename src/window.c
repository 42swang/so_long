#include "../include/so_long.h"

void	window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->map.map_width * 32, data->map.map_height * 32, "so_long");
	put_image(data);
	//키 이벤트를 감지하는 mlx_hook
	mlx_hook(data->win,	KEYPRESS, 0, &move, data);
	//키 이벤트로 생긴 변화를 뿌려줄 loop_hook
	mlx_loop_hook(data->mlx, &put_image, data);
	mlx_loop(data->mlx);
}