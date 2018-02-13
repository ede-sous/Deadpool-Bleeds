/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createObjs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:49:47 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/22 12:54:46 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h" 

/*
**			Creates a square obj
*/

t_obj				*X_CreateObject(SDL_Renderer *render, int x, int y, t_obj *prev, SDL_Color color) {

	t_obj			*obj;

	if ( !(obj = (t_obj*)malloc(sizeof(t_obj))) )
		return (NULL);

	obj->pos = X_CreatePosition(	x,
									y,
									OBJw,
									OBJh );

	obj->color = color;
	obj->sur = SDL_CreateRGBSurface(	0,					//-->Flags
										OBJw,					//-->Width
										OBJh,					//-->Height
										32,					//-->Depth
										0,					//-->Red Mask
										0,					//-->Green Mask
										0,					//-->Blue Mask
										0 );				//-->Alpha Mask

	SDL_FillRect(	obj->sur,
					NULL,
					SDL_MapRGBA(	obj->sur->format,
									color.r,
									color.g,
									color.b,
									color.a ));

	obj->text = SDL_CreateTextureFromSurface(	render,
												obj->sur );

	SDL_FreeSurface(obj->sur);
	obj->sur = NULL;

	obj->next = NULL;
	obj->prev = prev;
	obj->blood = 0;

	return ( obj );

}

/*
**			Creates a texture with the given image
*/

t_obj				X_CreateImg(SDL_Renderer *render, int x, int y, char *path) {

	t_obj			img;

	img.sur = IMG_Load(path);
	img.text = SDL_CreateTextureFromSurface(	render,
												img.sur );

	SDL_FreeSurface(img.sur);
	img.pos = X_CreatePosition(	x,
								y,
								IMGw,
								IMGh );
	
	img.blood = -1;

	return ( img );

}