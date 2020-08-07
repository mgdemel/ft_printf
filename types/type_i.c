/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:26:21 by malasalm          #+#    #+#             */
/*   Updated: 2020/08/07 17:29:38 by malasalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_i_right_prec(char *value, t_printf *data)
{
	if (data->precision < (int)ft_strlen(value))
	{
		data->precision = (int)ft_strlen(value);
		if (data->value < 0)
			data->precision--;
	}
	ft_putspaces(data->width - (data->precision + data->sign), data);
	if (data->sign == 1)
		value = ft_putsign(data, value);
	ft_putzeros(data->precision - ft_strlen(value), data);
}

void	ft_i_right_justify(char *value, t_printf *data)
{
	if (data->decimal == 0)
	{
		if (data->zero == 0)
		{
			if (data->value < 0)
				data->width++;
			ft_putspaces(data->width - (ft_strlen(value) + data->sign), data);
		}
		if (data->sign == 1)
			value = ft_putsign(data, value);
		if (data->zero == 1)
			ft_putzeros(data->width - (ft_strlen(value) + data->sign), data);
	}
	else
		ft_i_right_prec(value, data);
	ft_pf_putstr(value, data);
}

void	type_i(va_list args, t_printf *data)
{
	char *value;

	signed_converter(args, data);
	value = ft_itoa(data->value);
	if (data->value == 0 && data->decimal == 1 && data->precision == 0)
		value = "";
	if (data->minus == 1)
	{
		if (data->sign == 1)
			value = ft_putsign(data, value);
		if (data->precision < (int)ft_strlen(value))
			data->width = data->width - (ft_strlen(value) + data->sign);
		else
			data->width = data->width - (data->precision + data->sign);
		ft_putzeros(data->precision - ft_strlen(value), data);
		ft_pf_putstr(value, data);
		ft_putspaces(data->width, data);
	}
	else
		ft_i_right_justify(value, data);
}
