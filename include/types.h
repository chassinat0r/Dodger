#ifndef TYPES_H
#define TYPES_H

typedef enum {
    TITLE_SCENE,
    MAIN_SCENE,
    PAUSE_SCENE,
    GAMEOVER_SCENE
} Scene;

typedef struct {
    double left;
    double right;
    double top;
    double bottom;
} HitBox;

#endif
