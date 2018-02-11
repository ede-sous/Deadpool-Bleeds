/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:16:49 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 03:36:22 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int					main(int argc, char **argv) {

	t_game			game;
	SDL_Rect		renderPos = {
									.x = 0,					//-->X Position
									.y = 0,					//-->Y Position
									.w = rWIDTH,			//-->Width
									.h = rHEIGHT			//-->Height
								};

	srand(time(NULL));

	if (	SDL_Init(SDL_INIT_VIDEO) != 0
		|| 	TTF_Init() < 0
		|| 	IMG_Init(~0) < 0)
		return (1);

	if (!(game.window = SDL_CreateWindow(	"Deadpool Bleeds",			//-->Title
											SDL_WINDOWPOS_CENTERED,		//-->X Position
											SDL_WINDOWPOS_CENTERED,		//-->Y Position
											( game.width = WIDTH ),		//-->Width
											( game.height = HEIGHT ),	//-->Height
											SDL_WINDOW_SHOWN )))		//-->Flags
		return (1);

	if (!(game.render = SDL_CreateRenderer(	game.window,
											-1,
											SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC )))
		return (1);

	SDL_SetRenderDrawColor(	game.render,					//-->Render
                           	0,								//-->Red
                           	0,								//-->Green
                           	0,								//-->Blue
                           	255 );							//-->Alpha

	SDL_RenderFillRect(game.render, &renderPos);

	if (X_StartGame(&game))
	{
		printf("You did it !\n");
		return (1);
	}

	return (0);

}
