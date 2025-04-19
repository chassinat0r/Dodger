#include <gint/display.h>

#include "constants.h"
#include "enemy.h"

#include <math.h>

#include <stdlib.h>
#include <stdio.h>

void enemy_constructor(Enemy *enemy, double player_x, double player_y, double speed) {
    enemy->w = ENEMY_WIDTH;
    enemy->h = ENEMY_HEIGHT;

    double start_x = 0.5*(double)enemy->w;
    double end_x = WIDTH - 0.5*(double)enemy->h;
    int x_range = (int)end_x - (int)start_x;

    enemy->x = rand() % x_range;
    enemy->x += start_x;
    enemy->y = enemy->w;

    enemy->angle = atan((enemy->x - player_x) / (enemy->y - player_y));
    enemy->speed = speed;
    enemy->valid = true;
}

void enemy_dummy_constructor(Enemy *enemy) {
    enemy->x = -1;
    enemy->y = -1;
    enemy->w = -1;
    enemy->h = -1;
    enemy->angle = 0;
    enemy->valid = false;
}

void enemy_update(Enemy *enemy, int *points) {
    enemy->x += enemy->speed*sin(enemy->angle);
    enemy->y += enemy->speed*cos(enemy->angle);
    if (enemy->y + enemy->w > HEIGHT) {
        enemy->valid = false;
        *points = *points + 1;
    }
}

void enemy_draw(Enemy *enemy) {
    int start_x = enemy->x - 0.5*enemy->w;
    int end_x = enemy->x + 0.5*enemy->w;
    int start_y = enemy->y - 0.5*enemy->h;
    int end_y = enemy->y + 0.5*enemy->h;

    drect(start_x, start_y, end_x, end_y, C_WHITE);
}
