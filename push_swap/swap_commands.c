void	swap(char **a)
{
	char *temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	shift(char **a, int rot)
{
	char	*temp;
	int		i;

	if (rot == 1)
	{
		i = 1;
		temp = a[0];
		while (a[i])
		{
			a[i - 1] = a[i];
			i++;
		}
		a[i] = temp;
	}
	else
	{
		i = count(a);
		temp = a[i];
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = temp;
	}

}

void	push(char **a, char **b)
{
	
}
