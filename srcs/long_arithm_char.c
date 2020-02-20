/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_arithm_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:46:34 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/20 17:54:17 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  type == -1 -> rank += 1
*/

void	change_lanch_rank(t_lanch *p_lan, int type)
{
	t_lanch temp;

	temp.len = p_lan->len;
	if (type == -1)
	{
		cpy_lanch_str(&temp, p_lan);
		free(p_lan->num);
		p_lan->len += 1;
		cpy_lanch_str(p_lan, &temp);
		free(temp.num);
	}
	else
	{
		cpy_lanch_str(&temp, p_lan);
		free(p_lan->num);
		p_lan->len = type;
		cpy_lanch_str(p_lan, &temp);
		free(temp.num);
	}
}

void	power_of_five_lanch_inside(t_lanch *temp, int *c, int *r)
{
	if (*c == (int)temp->len)
		change_lanch_rank(temp, -1);
	temp->num[*c] = temp->num[*c] * 5 + *r;
	*r = (temp->num[*c] > 9) ? temp->num[*c] / 10 : 0;
	if (*r != 0)
		temp->num[*c] %= 10;
	(*c)++;
}

t_lanch	power_of_five_lanch(int num, int width)
{
	t_lanch	temp;
	int		remainder;
	int		c;
	int		cp;

	cp = num;
	remainder = 0;
	create_lanch(&temp, width);
	if (width == -1)
		temp.num[0] = 1;
	else
		temp.num[width - num] = 1;
	while (cp-- > 0)
	{
		c = (width == -1) ? 0 : width - num;
		while (c < (int)temp.len || remainder > 0)
			power_of_five_lanch_inside(&temp, &c, &remainder);
	}
	return (temp);
}

/*
**	TYPE
**	0 - > there are both parts
**	n - > there is only frac_part
*/

int		create_lanch_from_bitstr(t_lanch *res, char *str, int prec)
{
	int		c;
	int		len_str;
	int		length;

	len_str = ft_strlen(str);
	create_lanch(res, -1);
	c = len_str - 1;
	while (c > 0 && str[c] == '0')
		c--;
	*res = power_of_five_lanch(c + 1, -1);
	change_lanch_rank(res, c + 1);
	len_str = c;
	length = res->len;
	c = -1;
	while (++c < len_str)
		if (str[c] == '1')
			*res = sum_lanch_nums(*res, power_of_five_lanch(c + 1, length));
	return (precision_in_da_house(res, prec));
}

/*
**  f - first, s - second
*/

t_lanch	sum_lanch_nums(t_lanch f, t_lanch s)
{
	int		remainder;
	size_t	c;
	size_t	max;

	remainder = 0;
	c = 0;
	max = f.len > s.len ? f.len : s.len;
	while (c < max || remainder > 0)
	{
		if (c == f.len)
			change_lanch_rank(&f, 1);
		f.num[c] += remainder + (c < s.len ? s.num[c] : 0);
		remainder = (f.num[c] > 9) ? 1 : 0;
		if (remainder == 1)
			f.num[c] -= 10;
		c++;
	}
	return (f);
}
