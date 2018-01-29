/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createAssets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:51:26 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/22 11:50:00 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

/*
**		Creates a SDL_Rect with the given params
*/

SDL_Rect			X_CreatePosition(int x, int y, int w, int h) {

	SDL_Rect		pos = {
							.x = x,
							.y = y,
							.w = w,
							.h = h
						};

	return ( pos );

}

/*
**		Creates an SDL_Color with given/random params
*/

SDL_Color			X_CreateColor(int r, int g, int b) {

	int				random = rand() % 255;

	SDL_Color		color = {
								.r = (	r == -1
										? random
										: r ),
								.g = (	g == -1
										? random
										: g ),
								.b = (	b == -1
										? random
										: b ),
								.a = 255
							};

	return ( color );

}