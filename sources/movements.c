/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:07:41 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 07:46:25 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

static void				X_DeadpoolBleeds(t_game *game) {

	game->tmp = game->obj;
	while (game->tmp)
	{
		if ((	(game->tmp->pos.x + 12 >= game->img.pos.x
				&& game->tmp->pos.x + 12 <= game->img.pos.x + game->img.pos.w)
				||	(game->tmp->pos.x + game->tmp->pos.w - 12 >= game->img.pos.x
				&& game->tmp->pos.x + game->tmp->pos.w - 12 <= game->img.pos.x + game->img.pos.w))
				&&
				(	(game->tmp->pos.y + 12 >= game->img.pos.y
				&& game->tmp->pos.y + 12 <= game->img.pos.y + game->img.pos.h)
				||	(game->tmp->pos.y + game->tmp->pos.h - 12 >= game->img.pos.y
				&& game->tmp->pos.y + game->tmp->pos.h - 12 <= game->img.pos.y + game->img.pos.h)))
			X_ConditionDeadpool(game->tmp, game->render);
	
		game->tmp = game->tmp->next;
	}

}

static void			X_HorizontalMovement(t_game *game) {

	if (	MAPx > WIDTH / 2
		&&	MAPx + IMGw < rWIDTH - (WIDTH / 2))
	{

		game->tmp = game->obj;

		while (game->tmp)
		{

			if ( game->keys[SDL_SCANCODE_D] )
				game->tmp->pos.x -= MOUVE ;
			if ( game->keys[SDL_SCANCODE_A] )
				game->tmp->pos.x += MOUVE ;

			game->tmp = game->tmp->next;

		}

		if ( game->keys[SDL_SCANCODE_D] )
			game->back.pos.x -= MOUVE ;
		if ( game->keys[SDL_SCANCODE_A] )
			game->back.pos.x += MOUVE ;

	}

	else {

		if ( game->keys[SDL_SCANCODE_D] )
			game->img.pos.x += MOUVE ;
		if ( game->keys[SDL_SCANCODE_A] )
			game->img.pos.x -= MOUVE ;

	}
}

static void			X_VerticalMovement(t_game *game) {

	if (	MAPy > HEIGHT / 2
		&&	MAPy + IMGh < rHEIGHT - (HEIGHT / 2) )
	{

		game->tmp = game->obj;

		while (game->tmp)
		{

			if ( game->keys[SDL_SCANCODE_S] )
				game->tmp->pos.y -= MOUVE ;
			if ( game->keys[SDL_SCANCODE_W] )
				game->tmp->pos.y += MOUVE ;

			game->tmp = game->tmp->next;

		}

		if ( game->keys[SDL_SCANCODE_W] )
			game->back.pos.y += MOUVE ;
		if ( game->keys[SDL_SCANCODE_S] )
			game->back.pos.y -= MOUVE ;

	}
	else
	{

		if ( game->keys[SDL_SCANCODE_S] )
			game->img.pos.y += MOUVE ;
		if ( game->keys[SDL_SCANCODE_W] )
			game->img.pos.y -= MOUVE ;

		if ( game->img.pos.y < 0 )
			game->img.pos.y = 0;
		else if ( game->img.pos.y + IMGh > HEIGHT )
			game->img.pos.y = HEIGHT - IMGh;

	}

}

static void			X_MapMovement(t_game *game) {
	
	if ( game->keys[SDL_SCANCODE_D] )
		MAPx += MOUVE ;
	if ( game->keys[SDL_SCANCODE_A] )
		MAPx -= MOUVE ;
	if ( game->keys[SDL_SCANCODE_S] )
		MAPy += MOUVE ;
	if ( game->keys[SDL_SCANCODE_W] )
		MAPy -= MOUVE ;

	if ( MAPx < 0 )
		MAPx = 0;
	if ( MAPx > rWIDTH )
		MAPx = rWIDTH;
	if ( MAPy < 0 )
		MAPy = 0;
	if ( MAPy > rHEIGHT )
		MAPy = rHEIGHT;


	if ( MAPy <= HEIGHT / 2 )
		game->back.pos.y = 0;
	
	if ( MAPx <= WIDTH / 2 )
		game->back.pos.x = 0;

}

void				X_MoveObjects(t_game *game) {

	X_HorizontalMovement(game);
	X_VerticalMovement(game);
	X_MapMovement(game);
	X_DeadpoolBleeds(game);

}
