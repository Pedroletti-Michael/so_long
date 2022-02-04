#include "ft_printf.h"
#include "libft/libft.h"

int	process_u(unsigned long long n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = process_u(n / 10);
		count += ft_putchar_fd((n % 10) + '0', 1);
	}
	else
		count += ft_putchar_fd(n + '0', 1);
	return (count);
}
