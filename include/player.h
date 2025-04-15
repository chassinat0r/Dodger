#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Player;

void player_move(Player *player, int change_x, int change_y);
void player_draw(Player *player);

#endif
