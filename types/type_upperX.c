/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_upperX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:26:21 by malasalm          #+#    #+#             */
/*   Updated: 2020/08/11 17:41:48 by malasalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	type_X(va_list args, t_printf *data)
{
	char *base;

	base = unsigned_converter(args, data, 16);
	if (*base == '0' && data->decimal == 1 && data->precision == 0)
	{
		base = "";
		data->hash = 0;
	}
	if (data->hash == 1)
			data->hash = 2;
	if (data->minus == 1) // left justify!
	{	
		if (data->hash == 2)
			ft_pf_putstr("0X", data);
		ft_putzeros(data->precision - (ft_strlen(base) + data->hash), data);
		ft_pf_toupper(base, data);
		ft_putspaces(data->width - ft_strlen(base), data);
	}
	else // right justify!
	{
		if (data->decimal == 0)  // if there's only width or no width
		{
			ft_putspaces(data->width - (ft_strlen(base) + data->hash), data);
			if (data->hash == 2)
				ft_pf_putstr("0X", data);
		}
		else // if there's both width and precision or only prec
		{
			ft_putspaces(data->width - data->precision, data);
			if (data->hash == 2)
				ft_pf_putstr("0X", data);
			ft_putzeros(data->precision - (ft_strlen(base) + data->hash), data);
		}
		ft_pf_toupper(base, data);
	}
}
