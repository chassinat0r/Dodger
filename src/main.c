#include <gint/display.h>
#include <gint/keyboard.h>

#include <gint/clock.h>

#include "player.h"
#include "constants.h"
#include "types.h"

Player player;
Scene scene = TITLE_SCENE;

void init() {
	player.x = WIDTH / 2;
	player.y = HEIGHT;
	player.w = 20;
	player.h = 20;
	player.speed = 2;
	player.controls[CONTROL_LEFT] = false;
	player.controls[CONTROL_RIGHT] = false;
}

void handle_input() {
	key_event_t e = pollevent();

	switch (scene) {
		case TITLE_SCENE: {
			if (e.type == KEYEV_DOWN) {
				switch (e.key) {
					case KEY_F1: {
						scene = MAIN_SCENE;
						init();
						break;
					}
					case KEY_MENU: {
						getkey();
						break;
					}
				}
			}
			break;
		}
		case MAIN_SCENE: {
			if (e.type == KEYEV_DOWN) {
				switch (e.key) {
					case KEY_LEFT: {
						player_set_control(&player, CONTROL_LEFT, true);
						player_set_control(&player, CONTROL_RIGHT, false);
						break;
					}
					case KEY_RIGHT: {
						player_set_control(&player, CONTROL_RIGHT, true);
						player_set_control(&player, CONTROL_LEFT, false);						
						break;
					}
					case KEY_EXIT: {
						scene = PAUSE_SCENE;
						break;
					}
				}
			} else if (e.type == KEYEV_UP) {
				switch (e.key) {
					case KEY_LEFT: {
						player_set_control(&player, CONTROL_LEFT, false);
						break;
					}
					case KEY_RIGHT: {
						player_set_control(&player, CONTROL_RIGHT, false);
						break;
					}
				}
			}
			break;
		}
		case PAUSE_SCENE: {
			if (e.type == KEYEV_DOWN) {
				switch (e.key) {
					case KEY_F1: {
						scene = MAIN_SCENE;
						break;
					}
					case KEY_F2: {
						scene = TITLE_SCENE;
						break;
					}
				}
			}
			break;
		}
		default: {
			break;
		}
	}

}

void update() {
	switch (scene) {
		case MAIN_SCENE: {
			player_update(&player);
			break;
		}
		default: {
			break;
		}
	}
}

void draw() {
	dclear(C_BLACK);

	switch (scene) {
		case TITLE_SCENE: {
			dtext(0, 0, C_WHITE, "Dodger"); 
			dtext(0, 20, C_WHITE, "F1: Play");
			dtext(0, 30, C_WHITE, "F2: Tutorial");
			dtext(0, 40, C_WHITE, "MENU: Quit Dodger");

			break;
		}
		case MAIN_SCENE: {
			player_draw(&player);
			break;
		} 
		case PAUSE_SCENE: {
			dtext(0, 0, C_WHITE, "Paused"); 
			dtext(0, 20, C_WHITE, "F1: Resume");
			dtext(0, 30, C_WHITE, "F2: Return to menu"); 

			break;
		}
		case GAMEOVER_SCENE: {
			dtext(0, 0, C_WHITE, "Game Over"); 
			break;
		}
	}

	dupdate();
}

int main(void)
{
	init();

	for (;;) {
		handle_input();
		update();
		draw();
	}

	return 1;
}
