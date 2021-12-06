#ifndef Z_HDR_H_
# define Z_HDR_H_


/*
** includes
*/
#include "raylib.h"
#include <stdio.h>

/*
** defines
*/
#define MAX_COLUMNS 20
#define GAME_WIDTH 800
#define GAME_HEIGHT 450

/*
** structures and types used for various stuff
*/
typedef struct s_geo {
    float heights[MAX_COLUMNS];
    Vector3 positions[MAX_COLUMNS];
    Color colors[MAX_COLUMNS];
} t_geo;

typedef enum gameState
{LOADING = 0, TITLE, GAMEPLAY, ENDING} gameState;


/*
** functions for different screens
*/
int z_title( void );
int z_gameplay(Camera camera, t_geo * geo);

#endif
