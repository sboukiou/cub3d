#include "../includes/types.h"
#include "../includes/macros.h"
#include <mlx.h>

static int	load_single_texture(t_info *info, t_mlx *mlx, t_tex *tex, int texture_type)
{
	int	w;
	int	h;

	if (info == NULL)
		return (FAILURE);
	if (texture_type == LT_NORTH)
			tex->img = mlx_xpm_file_to_image(mlx->display, info->north_textures_file, &w, &h);
	else if (texture_type == LT_SOUTH)
			tex->img = mlx_xpm_file_to_image(mlx->display, info->south_textures_file, &w, &h);
	else if (texture_type == LT_WEST)
			tex->img = mlx_xpm_file_to_image(mlx->display, info->west_textures_file, &w, &h);
	else if (texture_type == LT_EAST)
			tex->img = mlx_xpm_file_to_image(mlx->display, info->east_textures_file, &w, &h);
	else if (texture_type == LT_DOOR)
			tex->img = mlx_xpm_file_to_image(mlx->display, info->door_textures_file, &w, &h);
	if (tex->img == NULL)
	{
		printf("Error: Could not load texture file for type %d\n", texture_type);
		return (FAILURE);
	}
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
	if (load_single_texture(info, mlx, &info->texs[LT_NORTH], LT_NORTH) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_SOUTH], LT_SOUTH) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_WEST], LT_WEST) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_EAST], LT_EAST) == FAILURE)
		return (FAILURE);
	if (load_single_texture(info, mlx, &info->texs[LT_DOOR], LT_DOOR) == FAILURE)
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
