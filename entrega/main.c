/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-jim <jose-jim@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:11:26 by jose-jim          #+#    #+#             */
/*   Updated: 2024/10/14 20:15:54 by jose-jim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx-linux/mlx.h"

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	if(NULL == mlx_ptr)
		return (MALLOC_ERROR);
	mlx_window = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "My Window");
	if(mlx_window == NULL)
		{
			mlx_destroy_display(mlx_ptr);
			free(mlx_ptr);
			return (MALLOC_ERROR);
		}
	mlx_loop(mlx_ptr);
	
	mlx_destroy_window(mlx_ptr,mlx_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}