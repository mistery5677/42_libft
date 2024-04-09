/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:26:20 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/09 16:01:13 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char	*str_big;
	char	*str_little;

	i = 0;
	str_big = (char *) big;
	str_little = (char *)little;
	if (ft_strlen(str_little) == 0)
		return (str_big);
	while (str_big[i] && i < len)
	{
		j = 0;
		while ((str_big[i + j] == str_little[j]) && i + j < len)
			j++;
		if (j >= ft_strlen(str_little))
			return (str_big + i);
		i++;
	}
	return (NULL);
}
