#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <sys/types.h>

int		main(int ac, char **av)
{
	int		fdIn;
	char	*recup1;
	char	*str;
	int		i = 2;

	if (ac == 2)
	{
		fdIn = open(av[1], O_RDONLY);
		while ((i = get_next_line(fdIn, &recup1)))
		{
			ft_putnbr(i);
			ft_putstr(" : \n");
			ft_putstr(recup1);
			ft_putstr("\n");
		}
		close(fdIn);
	}
	return (0);
}
