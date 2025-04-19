#ifndef ENEMY_H
#define ENEMY_H

typedef struct {
    double x;
    double y;
    int w;
    int h;
    double angle;
    double speed;
    bool valid;
} Enemy;

void enemy_constructor(Enemy *enemy, double player_x, double player_y, double speed);
void enemy_dummy_constructor(Enemy *enemy);

void enemy_update(Enemy *enemy, int *points);
void enemy_draw(Enemy *enemy);

#endif
