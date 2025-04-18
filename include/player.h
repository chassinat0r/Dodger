#ifndef PLAYER_H
#define PLAYER_H

#define CONTROL_LEFT 0
#define CONTROL_RIGHT 1

typedef struct {
    double x;
    double y;
    int w;
    int h;
    int speed;
    bool controls[2];
} Player;

void player_set_control(Player *player, int control, bool value);

void player_update(Player *player);
void player_draw(Player *player);

#endif
