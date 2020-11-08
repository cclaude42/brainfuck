/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck_visualizer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:43:57 by cclaude           #+#    #+#             */
/*   Updated: 2020/10/30 21:04:19 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	memfill(char *ptr, char *content)
{
	int		i = 0;

	while (content[i])
	{
		ptr[i] = content[i];
		i++;
	}
}

void	fill_top(char *screen, int h, int w)
{
	int	i = 0;
	int	j = 3 * w + 4;

	while (j < (h / 2) * w)
	{
		if (j % w > 2 && j % w < w - 3)
			screen[j] = 'o';
		j++;
	}
}

void	visualize(void)
{
	struct winsize size;
	int		h;
	int		w;
	char	*screen = malloc(w * h + 2);


	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	h = size.ws_row;
	w = size.ws_col;

	memset(screen, ' ', w * h);
	for (int i = 0 ; i < h ; i++)
	{
		screen[w * i + 1] = '#';
		screen[w * (i + 1) - 2] = '#';
	}
	memset(screen, 'B', w);
	memset(screen + w, ' ', w);
	memset(screen + 2 * w + 1, '#', w - 2);
	memset(screen + (h / 2) * w + 1, '#', w - 2);
	memset(screen + (h / 2 + 1) * w, ' ', w);
	memset(screen + (h / 2 + 2) * w + 1, '#', w - 2);
	memset(screen + (h - 2) * w + 1, '#', w - 2);
	memset(screen + (h - 1) * w, ' ', w);

	// fill_top(screen, h, w);

	screen[w * h] = '\n';
	screen[w * h + 1] = '\0';

	write(1, screen, w * h);
	// printf("%s\n", screen);
}

int		main(void)
{
	while (1)
	{
		visualize();
		usleep(1000000);
	}
	return (0);
}
