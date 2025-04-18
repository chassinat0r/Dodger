#include <gint/display.h>

#include "constants.h"
#include "enemy.h"

#include <math.h>

#include <stdlib.h>

void enemy_constructor(Enemy *enemy, double player_x, double player_y) {
    enemy->w = ENEMY_WIDTH;
    enemy->h = ENEMY_HEIGHT;

    int start_x = 0.5*enemy->w;
    int end_x = WIDTH - 0.5*enemy->h;
    int x_range = end_x - start_x;

    int start_y = 0.5*enemy->h;
    int end_y = 0.33*HEIGHT + 0.5*enemy->h;
    int y_range = end_y - start_y;

    enemy->x = rand() % x_range;
    enemy->x += start_x;
    enemy->y = rand() % y_range;
    enemy->y += start_y;

    enemy->angle = atan2(player_x - enemy->x, enemy->y - player_y);
}

void enemy_update(Enemy *enemy) {

}

void enemy_draw(Enemy *enemy) {
    int start_x = enemy->x - 0.5*enemy->w;
    int end_x = enemy->x + 0.5*enemy->w;
    int start_y = enemy->y - 0.5*enemy->h;
    int end_y = enemy->y + 0.5*enemy->h;
    drect(start_x, start_y, end_x, end_y, C_WHITE);
}
