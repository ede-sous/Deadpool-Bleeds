/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startGame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:15:41 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/28 23:52:59 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

/*
**			Starts the game ( OMG I did not noticed that ) 
*/

int					X_StartGame(t_game *game) {

	if (	!X_InitObjects(game)
		||	!X_InitMap(game))
		return (0);

	while (game->event.type != SDL_QUIT && !game->keys[SDL_SCANCODE_ESCAPE])
	{

		SDL_PollEvent(&game->event);

		X_MoveObjects(game);
		X_ObjsToWindow(game);

		SDL_RenderPresent(game->render);
		SDL_RenderClear(game->render);

		if (!X_VerifyBlood(game))
			return (1);

	}

	return (0);

}
