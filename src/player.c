#include <gint/display.h>

#include "player.h"
#include "constants.h"

void player_set_control(Player *player, int control, bool value) {
    player->controls[control] = value;
}

void player_update(Player *player) {
    if (player->controls[CONTROL_LEFT]) {
        player->x -= player->speed;
    } else if (player->controls[CONTROL_RIGHT]) {
        player->x += player->speed;
    }

    if (player->x < 0.5*player->w) {
        player->x = 0.5*player->w;
    }
    if (player->x > WIDTH - 0.5*player->w) {
        player->x = WIDTH - 0.5*player->w;
    }
}

void player_draw(Player *player) {
    int start_x = player->x - 0.5*player->w;
    int end_x = player->x + 0.5*player->w;
    int start_y = player->y - player->h;
    int end_y = player->y;
    drect(start_x, start_y, end_x, end_y, C_WHITE);
}
