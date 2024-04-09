/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:31:38 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/09 09:31:38 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s)) + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char my_function(unsigned int index, char character) {
	// Add any operation you want to perform on each character
	// For example, let's increment each character by 1
	return (character + 1);
}

int	main(void) {
	char strmapi_string[] = "Hello";
	printf("Input string: %s\n", input_string);

	char *result = ft_strmapi(input_string, &my_function);

	printf("Result: %s\n", result);
	free(result);
}*/
