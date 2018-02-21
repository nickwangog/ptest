/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:03:33 by dglaser           #+#    #+#             */
/*   Updated: 2018/02/21 14:07:01 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			preminpt2(uintmax_t z, int i, int zeros, t_flag *pf)
{
	if (d_len(z) < pf->prec)
	{
		while (zeros > 0)
		{
			write(1, "0", 1);
			zeros--;
			i++;
		}
	}
	ft_putnbr(z);
	i = i + d_len(z);
	while (pf->mwidth > i)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			ft_preminuspadding(uintmax_t z, t_flag *pf)
{
	int		i;
	int		zeros;

	zeros = pf->prec - d_len(z);
	i = 0;
	if (pf->pos == 1)
	{
		write(1, "+", 1);
		i++;
	}
	if (pf->neg == 1)
	{
		write(1, "-", 1);
		i++;
	}
	return (preminpt2(z, i, zeros, pf));
}

int			prezeropt2(uintmax_t z, int i, t_flag *pf)
{
	if (pf->neg == 1)
	{
		i++;
		ft_putchar('-');
	}
	while (pf->prec > d_len(z))
	{
		ft_putchar('0');
		pf->prec--;
	}
	i = i + d_len(z);
	if (z == 0 && pf->prec == 0)
	{
		ft_putchar(' ');
		i--;
	}
	else
		ft_putnbr(z);
	return (i + 1);
}

int			zppad(uintmax_t z, t_flag *pf)
{
	int		min;
	int		i;

	i = 0;
	if (pf->prec > d_len(z))
		min = pf->mwidth - pf->prec;
	else
		min = pf->mwidth - d_len(z);
	if (pf->pos == 1 || pf->neg == 1)
		min--;
	while (min > 0)
	{
		ft_putchar(' ');
		min--;
		i++;
	}
	if (pf->pos == 1)
	{
		i++;
		ft_putchar('+');
	}
	return (prezeropt2(z, i, pf));
}
