#include "enemy.h"
#include "constants.h"

#include <fxcg/display.h>

void enemy_init(Enemy *enemy) {
    enemy->x = rand() % WIDTH;
    enemy->y = 20;
    enemy->w = 15;
    enemy->h = 15;
}

void enemy_update(Enemy *enemy) {

}

void enemy_draw(Enemy *enemy) {
    int min_x = enemy->x - 0.5*enemy->w;
    if (min_x < 0) { min_x = 0; }
    int max_x = enemy->x + 0.5*enemy->w;
    if (max_x > WIDTH) { max_x = WIDTH; }

    int min_y = enemy->y - 0.5*enemy->h;
    if (min_y < 0) { min_y = 0; }
    int max_y = enemy->y + 0.5*enemy->h;
    if (max_y > HEIGHT) { max_y = HEIGHT; }

    for (int y = min_y; y <= max_y; y++) {
        for (int x = min_x; x <= max_x; x++) {
            Bdisp_SetPoint_VRAM(x, y, 63488);
        }
    }
}
