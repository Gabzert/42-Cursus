/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_phere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:27:29 by gfantech          #+#    #+#             */
/*   Updated: 2023/02/14 10:27:36 by gfantech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, float angle)
{
	float	y_new;
	float	z_new;

	y_new = *y * cos(angle) - *z * sin(angle);
	z_new = *y * sin(angle) + *z * cos(angle);
	*y = y_new;
	*z = z_new;
}

void	rotate_y(float *x, float *z, float angle)
{
	float	x_new;
	float	z_new;

	x_new = *x * cos(angle) + *z * sin(angle);
	z_new = *z * cos(angle) - *x * sin(angle);
	*x = x_new;
	*z = z_new;
}

void	rotate_z(float *x, float *y, float angle)
{
	float	x_new;
	float	y_new;

	x_new = *x * cos(angle) - *y * sin(angle);
	y_new = *x * sin(angle) + *y * cos(angle);
	*x = x_new;
	*y = y_new;
}
