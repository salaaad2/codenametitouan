#include "z_hdr.h"

int
z_titlescreen(long int frameCounter, gameState * currentState) {
    if (frameCounter > 500) {
        *currentState = TITLE;
    }
    return (0);
}
