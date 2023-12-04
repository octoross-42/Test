/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:33:58 by octoross          #+#    #+#             */
/*   Updated: 2023/10/25 21:33:58 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 800

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_window
{
    void	*mlx;
    void	*win;
	t_img	*img;
}	t_window;

char	*get_next_line(int fd);

#endif