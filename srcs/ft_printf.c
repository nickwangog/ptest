/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:08:50 by nwang             #+#    #+#             */
/*   Updated: 2018/02/05 22:13:04 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_count(const char *f, int i)
{
	int	j;

	j = 0;
	while(f[i] && !(check_spec(f[i])) && f[i] != '%')
	{
		i++;
		j++;
	}
	return(j + 1);
}

int		man_flag(const char *f, int i, t_flag *pf)
{
	int a;
	int b;

	a = 1;
	which_flag(f, i + 1, pf);
	b = valid_char(f, i + 1, pf);
	which_mods(f, i + 1, pf);
	a = char_count(f, i + 1);
	if (b == 0)
	{
		ft_putendl("Error");
		return (-1);
	}
	return (a + i);


}

int		ft_percent(int i, int *flag, size_t *num)
{
	write(1, "%", 1);
	*num = *num + 1;
	*flag = 1;
	return (i + 2);
}

int		ft_new(const char *fo, t_flag *pf, va_list ap, size_t num)
{
	int				flag;
	static size_t	i;

	flag = 0;
	ft_bzero(pf, sizeof(t_flag));
	while ((fo[i] != '\0') && (fo[i] != '%') && (i < ft_strlen(fo)))
	{
		write(1, &fo[i], 1);
		i++;
		num++;
	}
	if (fo[i] != '\0' && fo[i] == '%' && fo[i + 1] != '%' && (flag = 1))
	{
		if ((i = man_flag(fo, i, pf) + 1) == 0)
			return (0);
	}
	else if (fo[i] != '\0' && fo[i] == '%' && fo[i + 1] == '%')
		i = ft_percent(i, &flag, &num);
	if (flag == 1)
	{
		num = num + output(ap, pf);
		num = ft_new(fo, pf, ap, num);
	}
	i = 0;
	return (num);
}


/*int		ft_check(const char *f,	t_flag *pf, va_list ap, size_t res)
{
	//static size_t	i;
	int i = 0;
	int				fl;
	
	fl = 0;
	ft_bzero(pf, sizeof(t_flag));
	while (f[i])
	{
		while ((f[i] && f[i] != '%') && (i < (int)ft_strlen(f)))
		{
			ft_putchar(f[i++]);
			res++;
		}
		if (f[i] && f[i] == '%' && f[i + 1] != '%' && (fl = 1))
		{
			if ((i = man_flag(f, i, pf) + 1) == 0)
				return (0);
			i++;
		}
		else if (f[i] && f[i] == '%' && f[i + 1] == '%')
		{
			ft_putchar('%');
			res += 1;
			fl = 1;
			i += 2;
		}
		if (fl == 1)
			res = res + output(ap, pf);
	}
	return (res);
}*/

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int count;
	size_t	j;
	t_flag	pf;

	j = 0;	
	va_start(ap, format);
	count = ft_new(format, &pf, ap, j);
	va_end(ap);
	return (count);
}
