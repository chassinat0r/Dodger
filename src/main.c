#include <fxcg/display.h>
#include <fxcg/keyboard.h>

#include "player.h"
#include "constants.h"

Player player;

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
        int key;
        GetKey(&key);
    }
}

void draw() {
    Bdisp_AllClr_VRAM();
    
    player_draw(&player);
    
    Bdisp_PutDisp_DD();
}

void update() {
    player_update(&player);
}

void main(void) {
    Bdisp_EnableColor(1);
    player.x = 0.5*WIDTH;
    player.y = HEIGHT;
    player.w = 20;
    player.h = 20;

    for(;;){
        handle_input();
        update();
        draw();
    }
}
