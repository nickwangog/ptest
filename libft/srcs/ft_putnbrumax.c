/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrumax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:12:09 by nwang             #+#    #+#             */
/*   Updated: 2018/02/01 21:19:49 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrumax(uintmax_t a)
{
	if (a >= 10)
	{
		ft_putnbrumax(a / 10);
		ft_putnbrumax(a % 10);
	}
	else
		ft_putchar(a + '0');
}