/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putToWindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:11:14 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 03:49:24 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

/*
**			Print every object in the window
*/

void				X_ObjsToWindow(t_game *game) {

	//	Puts Background to Window

	SDL_RenderCopyEx(	game->render,
						game->back.text,	
						NULL,
						&game->back.pos,	
						0,
						NULL,
						0 );

	//	Puts Squares to Window

		game->tmp = game->obj;

		while (game->tmp)
		{
			SDL_RenderCopyEx(	game->render,
								game->tmp->text,
								NULL,
								&game->tmp->pos,
								0,
								NULL,
								0 );

			if (!game->tmp->next)
				break ;

			game->tmp = game->tmp->next;

		}

	//	Puts Deadpool Img to Window

		SDL_RenderCopyEx(	game->render,
							game->img.text,	
							NULL,
							&game->img.pos,	
							0,
							NULL,
							0 );

	//	Puts Score to Window

		SDL_RenderCopyEx(	game->render,
							game->score.text,
							NULL,
							&game->score.pos,
							0,
							NULL,
							0 );

}