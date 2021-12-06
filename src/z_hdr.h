#ifndef Z_HDR_H_
# define Z_HDR_H_

/*
**
** structures and types used for various stuff
*/
typedef enum gameState
{LOADING = 0, TITLE, DIFFICULTY, GAMEPLAY, END} gameState;


/*
** functions for different screens
*/
int z_titlescreen(long int frameCounter, gameState *currentState);

#endif
