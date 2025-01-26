/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miaghabe <miaghabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:57 by miaghabe          #+#    #+#             */
/*   Updated: 2025/01/26 16:57:24 by miaghabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*str++);
	return (len);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	int		len;

	len = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_puthex(n / 16, uppercase);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	convert_to_hex(unsigned long long num, int is_lower_case)
{
	int		length;
	char	*hex_base;

	if (is_lower_case)
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	length = 0;
	if (num >= 16)
		length += convert_to_hex(num / 16, is_lower_case);
	length += ft_putchar(hex_base[num % 16]);
	return (length);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	p;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		return (3);
	}
	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (convert_to_hex(p, 1) + 2);
}
