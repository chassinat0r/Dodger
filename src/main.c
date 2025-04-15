#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <fxcg/rtc.h>

#include <time.h>

#include "player.h"
#include "constants.h"
#include "enemy.h"

Player player;
Enemy enemy;
int running = 0;

static int keyPressed(int basic_keycode){
    const unsigned short* keyboard_register = (unsigned short*)0xA44B0000;
    int row, col, word, bit;
    row = basic_keycode%10;
    col = basic_keycode/10-1;
    word = row>>1;
    bit = col + ((row&1)<<3);
    return (0 != (keyboard_register[word] & 1<<bit));
}

void handle_input() {
    if (keyPressed(KEY_PRGM_LEFT)) {
        player_move(&player, -1, 0);
    } else if (keyPressed(KEY_PRGM_RIGHT)) {
        player_move(&player, 1, 0);
    } 
    
    if (keyPressed(KEY_PRGM_MENU)) {
        running = 0;
        int key;
        GetKey(&key);
    }
}

void draw() {
    Bdisp_AllClr_VRAM();
    
    player_draw(&player);
    enemy_draw(&enemy);

    Bdisp_PutDisp_DD();
}

void update() {
    player_update(&player);
    enemy_update(&enemy);
}

void init() {
    srand(RTC_GetTicks());

    Bdisp_EnableColor(1);
    player.x = 0.5*WIDTH;
    player.y = HEIGHT;
    player.w = 20;
    player.h = 20;

    enemy_init(&enemy);

    running = 1;
}

void main(void) {
    init();

    for(;;){
        handle_input();
        update();
        draw();
        if (running == 0) {
            init();
        }
    }
}
