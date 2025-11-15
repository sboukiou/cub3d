#include "../includes/types.h"
#include "../includes/macros.h"
#include "../lib/mlx_linux/mlx.h"

static int	load_single_texture(t_info *info, t_mlx *mlx, t_tex *tex)
{
	int	w;
	int	h;

	if (info == NULL)
		return (FAILURE);
	info->texs[LT_NORTH].img = mlx_xpm_file_to_image(mlx->display,
			info->north_textures_file, &w, &h);
	if (info->texs[LT_NORTH].img == NULL)
		return (FAILURE);
	tex->data = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->llen, &tex->endian);
	tex->width = w;
	tex->height = h;
	return (SUCCESS);
}

int	load_textures(t_info *info, t_mlx *mlx)
{
	if (info == NULL || mlx == NULL)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_NORTH]) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_SOUTH]) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_WEST]) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_EAST]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

unsigned int	textures_get_pixel(t_tex *tex, int tx, int ty)
{
	unsigned int	color;
	char			*pixel_address;
	int				bytes;
	int				i;

	if (tex == NULL || tex->data == NULL)
		return (0X000000);
	
	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	if (ty >= tex->height)
		ty = tex->height - 1;
	bytes = tex->bpp / 8;
	pixel_address = tex->data + ty * tex->llen + tx * bytes;
	color = 0;
	if (bytes == 4)
	{
		color = *(unsigned int *)pixel_address;
		return (color);
	}
	i = 0;
	while (i < bytes)
	{
		color |= (unsigned char)pixel_address[i] << (8 * i);
		i += 1;
	}
	return (color);
}
