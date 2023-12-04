/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:36:18 by octoross          #+#    #+#             */
/*   Updated: 2023/10/25 21:36:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	*ft_init_image(t_window *window)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->width = WINDOW_WIDTH;
	img->height = WINDOW_HEIGHT;
	img->img = mlx_new_image(window->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->size_line), &(img->endian));
	return (img);
}

t_window	*ft_init_window(void)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	if (!window->mlx)
		return (free(window), NULL);
	window->win = mlx_new_window(window->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf Octoross");
	if (!window->win)
	{
		mlx_destroy_display(window->mlx);
		free(window->win);
		return (free(window), NULL);
	}
	window->img = ft_init_image(window);
	if (window->img == NULL)
	{
		mlx_destroy_display(window->mlx);
		free(window->win);
		mlx_destroy_window(window->mlx, window->win);
		return (free(window), NULL);
	}
	return (window);
}


int	ft_close_win(void *params)
{
	t_window	*window;
	int		x;
	int		y;

	window = (t_window *)params;
	mlx_destroy_image(window->mlx, window->img->img);
	free(window->img);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
	exit(0);
}

int	ft_mouse_down(int button, int x, int y, void *params)
{
	printf("OUIIIIIIIIIIIIIIIIIII\n");
}

int	ft_mouse_up(int button, int x, int y, void *params)
{
	printf("ALL THE WAY UP ALL THE WAY UP ALL THE WAY UP\n");
}

int	ft_key_press(int keycode, void *params)
{
	printf("FALLING IN LOOOOOOVE WITH YOUUUUUUUUUUUUUUUU\n");
}

int	ft_mouse_move(int button, int x, int y, void *params)
{
	printf("LALALLALALAMALALALLALALAL\n");
}

void	ft_init_display(t_window *window)
{
	mlx_hook(window->win, 2, 0, ft_key_press, window);
	mlx_hook(window->win, 4, 0, ft_mouse_down, window);
	mlx_hook(window->win, 5, 0, ft_mouse_up, window);
	mlx_hook(window->win, 6, 0, ft_mouse_move, window);
	mlx_hook(window->win, 17, 0, ft_close_win, window);
	mlx_loop(window->mlx);
}

int	main(int argc, char **argv)
{
	t_window	*window;
	int			fd;

	// if (argc < 2)
	// 	return (printf("Error : No map\n"), 1);
	// // map = ft_get_map(argv[1], argc - 1, &argv[1]);
	// if (!map)
	// 	return (printf("Error : cannot open/read map or malloc\n"), 1);
	window = ft_init_window();
	if (!window)
		return (printf("Error : window\n"), 1);
	ft_init_display(window);
}
