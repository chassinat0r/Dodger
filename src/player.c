#include "player.h"
#include "util.h"
#include "constants.h"

#include <fxcg/display.h>

void player_move(Player *player, int change_x, int change_y) {
    player->x += change_x;
    player->y += change_y;
}

void player_update(Player *player) {
    if (player->x - 0.5*player->w < 0) {
        player->x = 0.5*player->w;
    }
    if (player->x + 0.5*player->w > WIDTH) {
        player->x = WIDTH - 0.5*player->w;
    }
}

void player_draw(Player *player) {
    int min_x = player->x - 0.5*player->w;
    if (min_x < 0) { min_x = 0; }
    int max_x = player->x + 0.5*player->w;
    if (max_x > WIDTH) { max_x = WIDTH; }

    int min_y = player->y - player->h;
    if (min_y < 0) { min_y = 0; }
    int max_y = player->y;
    if (max_y > HEIGHT) { max_y = HEIGHT; }

    for (int y = min_y; y <= max_y; y++) {
        for (int x = min_x; x <= max_x; x++) {
            Bdisp_SetPoint_VRAM(x, y, 63488);
        }
    }
}
