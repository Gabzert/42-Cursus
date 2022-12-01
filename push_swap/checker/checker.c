
#include "checker.h"


int	cmd_check(	t_stack	*a, t_stack	*b)
{
	char	*cmd;

	while (sort_check(a) == 0)
	{
		cmd = get_next_line(1);
		if (ft_strncmp(cmd, "sa", 5) == 0)
			swap(a);
		if (ft_strncmp(cmd, "sb", 5) == 0)
			swap(b);
		if (ft_strncmp(cmd, "ra", 5) == 0)
			shift(a);
		if (ft_strncmp(cmd, "rb", 5) == 0)
			shift(b);
		if (ft_strncmp(cmd, "rra", 5) == 0)
			rev_shift(a);
		if (ft_strncmp(cmd, "rrb", 5) == 0)
			rev_shift(b);
		if (ft_strncmp(cmd, "rr", 5) == 0)
			dshift(a, b , 0);
		if (ft_strncmp(cmd, "rrr", 5) == 0)
			dshift(a ,b, 1);
		if (cmd == NULL)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = -1;
	argc -= 1;
	a.array = ft_calloc(argc, sizeof(int *));
	a.size = argc;
	b.array = ft_calloc(a.size, sizeof(int *));
	b.size = 0;
	if (input_check(argc, argv) == 1)
		write(2, "Error\n", 6);
	else
	{
		while (++i < argc)
			a.array[i] = ft_atoi(argv[i + 1]);
		if (cmd_check(&a, &b) == 1)
			write(2, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	return (0);
}