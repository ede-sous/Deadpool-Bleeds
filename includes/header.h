/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2018/01/29 05:00:20 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "sys_inc.h"
# include "const_vars.h"

typedef struct			s_obj
{
	SDL_Surface			*sur;
	SDL_Texture			*text;
	SDL_Rect			pos;
	SDL_Color			color;
	int					blood;
	struct s_obj		*next;
	struct s_obj		*prev;
}						t_obj;

typedef struct			s_game
{
	SDL_Window			*window;
	SDL_Renderer		*render;
	SDL_Event			event;
	SDL_Rect			render_pos;
	SDL_Rect			map;
	TTF_Font			*font;
	t_obj				score;
	t_obj				back;
	t_obj				img;
	t_obj				*obj;
	t_obj				*tmp;
	size_t				width;
	size_t				height;
	const Uint8			*keys;
}						t_game;

/*
**
**						Minilib
**
*/

int						ft_isval(int nb);
int						ft_strcmp(const char *s1, const char *s2);

void					ft_strdel(char **as);

size_t					ft_strlen(const char *s);

char					*ft_itoa(int n);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2, int value);

/*
**
**						Creaters and Initializers
**
*/

int						X_InitObjects(t_game *game);
int						X_InitMap(t_game *game);

t_obj					X_CreateImg(SDL_Renderer *render, int x, int y, char *path);
t_obj					*X_CreateObject(SDL_Renderer *render, int x, int y, t_obj *prev, SDL_Color color);

SDL_Color				X_CreateColor(int r, int g, int b);
SDL_Rect				X_CreatePosition(int x, int y, int w, int h);

/*
**
**						Modifiers
**
*/

void					X_ConditionDeadpool(t_obj *tmp, SDL_Renderer *render);
void					X_MoveObjects(t_game *game);
void					X_ObjsToWindow(t_game *game);

/*
**
**						Game Start / End Function
**
*/

int						X_StartGame(t_game *game);
int						X_VerifyBlood(t_game *game);

#endif
