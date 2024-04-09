/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:33 by miafonso          #+#    #+#             */
/*   Updated: 2024/04/08 14:06:33 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) != 1)
			return ;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
}

/*int main()
{
		printf("TESTING FT_PUTNBR_FD \n\n");
	int fd_putnbr = open("fd_putendl.txt",
			O_CREAT | S_IRWXU | O_WRONLY | O_APPEND, 0666);
	if (fd_putnbr == -1)
		perror("open");
	else
		printf("ficheiro criado com sucesso\n\n");
	ft_putnbr_fd(2147483647, fd_putnbr);
}*/