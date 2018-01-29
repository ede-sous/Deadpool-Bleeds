/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadpoolBleedsConditions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:46:37 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 07:40:11 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

void			X_ConditionDeadpool(t_obj *tmp, SDL_Renderer *render) {

	tmp->sur = SDL_CreateRGBSurface(	0,
										OBJw,
										OBJh,
										32,					//-->Depth
										0,					//-->Red Mask
										0,					//-->Green Mask
										0,					//-->Blue Mask
										0 );				//-->Alpha Mask

	SDL_FillRect(	tmp->sur,
					NULL,
					SDL_MapRGBA(	tmp->sur->format,
									BLOOD,
									0,
									0,
									255 ));

	SDL_DestroyTexture(tmp->text);
	tmp->text = NULL;

	tmp->text = SDL_CreateTextureFromSurface(	render,
												tmp->sur );

	SDL_FreeSurface(tmp->sur);
	tmp->sur = NULL;

	tmp->blood = 1;

}

int				X_VerifyBlood(t_game *game) {

	char		*score;
	int			nb = -1;

	game->tmp = game->obj;

	while (game->tmp)
	{
		if (game->tmp->blood)
			nb++;
		game->tmp = game->tmp->next;
	}

	score = ft_strjoin(	ft_itoa(MAPnb - nb),
						" Squares missing ! ",
						0 );

	if (!(game->score.sur = TTF_RenderText_Blended(	game->font,
													score,
													X_CreateColor(255, 255, 255))))
		printf("%s\n", SDL_GetError());

	if (game->score.text)
		SDL_DestroyTexture(game->score.text);
	game->score.text = NULL;

	game->score.text = SDL_CreateTextureFromSurface(game->render, game->score.sur);

	SDL_FreeSurface(game->score.sur);
	game->score.sur = NULL;

	game->score.pos.x = 25;
	game->score.pos.y = 25;
	game->score.pos.w = WIDTH / 8;
	game->score.pos.h = HEIGHT / 40;

	if (nb >= MAPnb)
		return (0);
	
	return (1);

}