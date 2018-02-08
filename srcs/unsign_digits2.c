/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_digits2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:24:59 by nwang             #+#    #+#             */
/*   Updated: 2018/02/05 21:24:43 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		oct(uintmax_t i, int len, t_flag *pf)
{
	char	*s;
	int		z;

	s = unbase(i, 8);
	len = ft_strlen(s);
	if (pf->hash == 1)
		len++;
	z = pf->prec - len;
	z > 0 ? len += z : 0;
	if (pf->hash == 1)
		ft_putnbr(0);
	if (pf->minus == 0)
		len = len + pad(pf->mwidth - len, *pf);
	while (z-- > 0)
		ft_putnbr(0);
	if (pf->hash == 0 && pf->dot == 0 && i == 0)
	{
		ft_putnbr(0);
		len++;
	}
	ft_putstr(s);
	free(s);
	if (pf->minus == 1)
		len = len + pad(pf->mwidth - len, *pf);
	return (len);
}

int		hex(uintmax_t i, t_flag *pf)
{
	char	*s;
	int		len;

	if (pf->dot == 1 && pf->mwidth == 0 && i == 0)
		return (0);
	s = hexbase(i, (pf->cha == 'x' ? 0 : 1));
	len = ft_strlen(s);
	i != 0 && pf->hash ? len += 2 : len;
	if (pf->zero == 0 || pf->minus)
	{
		if (pf->hash == 1 && pf->cha == 'x' && i != 0)
			ft_putstr("0x");
		if (pf->hash == 1 && pf->cha == 'X' && i != 0)
			ft_putstr("0X");
	}
	if (pf->dot == 1 && i == 0)
		ft_putchar(' ');
	if (pf->minus == 0 || pf->minus == 1)
		len = len + pad(pf->mwidth - len, *pf);
	else
		ft_putstr(s);
	free(s);
	return (len);
}

int		uint(uintmax_t i, t_flag *pf)
{
	int len;

	len = 1;
	while (i /= 10)
		len++;
	if (pf->minus == 0 || pf->minus == 1)
		len += pad(pf->mwidth - d_len(i), *pf);
	if (pf->minus == 0 && pf->dot == 1)
		while (len++ < pf->prec)
			ft_putchar('0');
	ft_putnbrumax(i);
	return (len);
}