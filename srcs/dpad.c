/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:57:52 by nwang             #+#    #+#             */
/*   Updated: 2018/02/16 20:14:30 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			minpad(uintmax_t z, int i, int x, t_flag *pf)
{
	x = pf->prec - d_len(z);
	if (pf->neg == 1 && i++)
		ft_putchar('-');
	if (pf->pos == 1 && i++)
		ft_putchar('+');
	if (d_len(z) < pf->prec)
		while (x > 0)
		{
			ft_putchar('0');
			i++;
			x--;
		}
	ft_putnbr(z);
	i += d_len(z);
	while (pf->mwidth > i)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			zppad(uintmax_t z, int i, int x, t_flag *pf)
{
	pf->prec > d_len(z) ? (x = (pf->mwidth - pf->prec))
			: (x = (pf->mwidth - d_len(z)));
	if (pf->pos == 1 || pf->neg == 1)
		x--;
	while (x > 0)
	{
		ft_putchar(' ');
		i++;
		x--;
	}
	if (pf->pos == 1 && i++ >= 0)
		ft_putchar('+');
	if (pf->neg == 1 && i++ >= 0)
		ft_putchar('-');
	while (pf->prec-- > d_len(z))
		ft_putchar('0');
	i += d_len(z);
	if (pf->prec == 0 && z == 0)
	{
		ft_putchar(' ');
		i--;
	}
	else
		ft_putnbr(z);
	return (i + 1);
}
