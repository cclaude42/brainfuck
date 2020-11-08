/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:28:33 by cclaude           #+#    #+#             */
/*   Updated: 2020/10/30 20:03:07 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*brainfuck(FILE *f, char *ptr)
{
	char	c;

	while ((c = fgetc(f)) != EOF)
	{
		if (c == '>')
			ptr++;
		else if (c == '<')
			ptr--;
		else if (c == '+')
			(*ptr)++;
		else if (c == '-')
			(*ptr)--;
		else if (c == '.')
			write(1, ptr, 1);
		else if (c == ',')
			*ptr = getchar();
		else if (c == '[')
		{
			while (*ptr)
			{
				long	l = ftell(f);
				ptr = brainfuck(f, ptr);
				fseek(f, l, SEEK_SET);
			}
			int	b = 0;
			while ((c = fgetc(f)) != ']' || b)
			{
				if (c == '[')
					b++;
				else if (c == ']')
					b--;
			}
		}
		else if (c == ']')
			return (ptr);
	}
	return (ptr);
}


int		main(int ac, char **av)
{
	FILE	*f;
	char	*ptr;

	if (ac != 2)
	{
		printf("Invalid number of arguments. Usage :\n%s [FILE]\n", av[0]);
		return (1);
	}
	f = fopen(av[1], "rb");
	if (!f)
	{
		printf("Invalid file.\n");
		return (1);
	}
	ptr = calloc(30000, 0);
	if (!ptr)
	{
		printf("Allocation failure.\n");
		return (1);
	}
	brainfuck(f, ptr);
	free(ptr);
	return (0);
}
