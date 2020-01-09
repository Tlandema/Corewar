/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:03 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/09 11:12:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	creates generic object to specific functions.
*/

static SDL_Point	create_name_point(int champ_n)
{
	int	x;
	int	y;

	x = 1840 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 170 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_point(x, y));
}

static SDL_Point	create_alive_point(int champ_n)
{
	int	x;
	int	y;

	x = 1840 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 370 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_point(x, y));
}

static SDL_Rect		create_champ_rect(int champ_n)
{
	int	x;
	int	y;

	x = 1810 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 155 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_rect(x, y, 242, 242));
}

int8_t				draw_champion_face(t_window *win, t_vm *env, int champ_n,
					SDL_Point point)
{
	int	text[3];

	if (create_tab_int3(text, 25, 19 + champ_n, BOLD) == FAILURE)
		return (FAILURE);
	point.x += 30;
	point.y += 70;
	//if (champ_n != env->winner_index && )
	//{
	//	if (draw_text(win, "X       X", point, text) == FAILURE)
	//		return (FAILURE);
	//}
	/*else */if (draw_text(win, "0       0", point, text) == FAILURE)
		return (FAILURE);
	point.y += 70;
	point.x -= 10;
	if (env->champ[champ_n].last_live_cycle == FAILURE
			|| env->current_cycle > 200)
	{
		if (draw_text(win, "/----------\\", point, text) == FAILURE)
			return (FAILURE);
	}
	else if (draw_text(win, "\\----------/", point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
**	Draws the champions depending of how many of them there is.
*/

int8_t				draw_champions(t_window *win, t_vm *env, int champ_n)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			text[3];
	int			tmp;

	tmp = 19 + champ_n;
	if (create_tab_int3(text, 13, tmp, BOLD) == FAILURE)
		return (FAILURE);
	point = create_name_point(champ_n);
	pos = create_champ_rect(champ_n);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_champion_name(win, (char *)env->champ[champ_n].name, point,
			text) == FAILURE)
		return (FAILURE);
	if (draw_champion_face(win, env, champ_n, point) == FAILURE)
		return (FAILURE);
	point = create_alive_point(champ_n);
	point.x += (tmp = draw_text(win, "Last time alive : ", point, text));
	if (tmp == FAILURE)
		return (FAILURE);
	if (draw_last_live(win, env->champ[champ_n].last_live_cycle,
		point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
