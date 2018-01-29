/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initObjects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:10:32 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 06:29:01 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

/*
**			Initializes the first Object and Image ( Oh ... I thought it made puppies )
*/

int					X_InitObjects(t_game *game) {

	game->img = X_CreateImg(	game->render,
								( WIDTH / 2 ) - (IMGw),
								( HEIGHT / 2 ) - (IMGh),
								"stock/p.png" );

	game->obj = X_CreateObject(	game->render,
								( WIDTH / 4 ) - (OBJw / 2),
								( HEIGHT / 4 ) - (OBJh / 2),
								NULL,
								X_CreateColor(255, 255, 255));

	game->back = X_CreateImg(	game->render,
								0,
								0,
								"stock/back.jpg" );
	game->back.pos.w = rWIDTH;
	game->back.pos.h = rHEIGHT;
	
	if (!game->obj)
		return (0);

	game->tmp = game->obj;

	game->keys = SDL_GetKeyboardState(NULL);
	game->map = X_CreatePosition(game->img.pos.x, game->img.pos.y, rWIDTH, rHEIGHT);

	game->score.text = NULL;
	
	return (1);
}

/*
**			Initializes the map ( Oh ... I thought it made a cat poop )
*/

int					X_InitMap(t_game *game) {

	size_t			i = 0;

	game->tmp = game->obj;
	while (i++ < MAPnb)
	{

		if (!(game->tmp->next = X_CreateObject(	game->render,
												(int)(rand() % (rWIDTH)),
												(int)(rand() % (rHEIGHT)),
												game->tmp,
												X_CreateColor(-1, -1, -1))))
			return (0);

		game->tmp = game->tmp->next;

	}

	if (!(game->font = TTF_OpenFont("./stock/Arial.ttf", 150)))
	{
		printf("%s\n", TTF_GetError());
		return (0);
	}

	return (1);

}