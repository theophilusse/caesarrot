#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> /** atoi **/

int			lowercase(char c)
{
	return (c >= 'a' && c <= 'z' ? 1 : 0);
}

int			uppercase(char c)
{
	return (c >= 'A' && c <= 'Z' ? 1 : 0);
}

int			isalphabet(char c)
{
	if (lowercase(c) || uppercase(c))
		return (1);
	return (0);
}

char		ABC(char c, int rot)
{
	c += rot;
	if (c > 'Z')
		return ('A' + (c - 'Z' - 1));
	return (c);
}

char		abc(char c, int rot)
{
	c += rot;
	if (c > 'z')
		return ('a' + (c - 'z' - 1));
	return (c);
}

int			abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

char		help[] = "Usage: [n] [text]\n";

int		main(int ac, char **av)
{
	char		*i;
	char		b;
	char		nl;
	int			rot;

	if (ac != 3)
		return (write(1, help, 18));
	i = av[2] - 1;
	rot = atoi(av[1]);
	while (*(++i) != '\0')
	{
		b = *i;
		if (isalphabet(b))
		{
			if (lowercase(*i))
				b = abc(*i, abs(rot));
			if (uppercase(*i))
				b = ABC(*i, abs(rot));
		}
		write(1, &b, 1);
	}
	nl = '\n';
	write(1, &nl, 1);
	return (1);
}
