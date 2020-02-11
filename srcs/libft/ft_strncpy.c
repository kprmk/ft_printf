/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:37 by mbrogg            #+#    #+#             */
/*   Updated: 2020/02/11 15:23:44 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	if ((dst = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	while (src[count] != '\0' && count < n)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < n)
		dst[count++] = '\0';
	return (dst);
}