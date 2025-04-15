#include "util.h"

#include <fxcg/display.h>
#include <fxcg/keyboard.h>

void plot(unsigned x,unsigned y,unsigned short color){
    unsigned short*s=(unsigned short*) GetVRAMAddress;
    s+=(y*384)+x;
    *s=color;
}

void drawLine(int x1, int y1, int x2, int y2, unsigned short color) {
    signed char ix;
    signed char iy;
 
    // if x1 == x2 or y1 == y2, then it does not matter what we set here
    int delta_x = (x2 > x1?(ix = 1, x2 - x1):(ix = -1, x1 - x2)) << 1;
    int delta_y = (y2 > y1?(iy = 1, y2 - y1):(iy = -1, y1 - y2)) << 1;
 
   plot(x1, y1, color);  
    if (delta_x >= delta_y) {
        int error = delta_y - (delta_x >> 1);        // error may go below zero
        while (x1 != x2) {
            if (error >= 0) {
                if (error || (ix > 0)) {
                    y1 += iy;
                    error -= delta_x;
                }                           // else do nothing
         }                              // else do nothing
            x1 += ix;
            error += delta_y;
            plot(x1, y1, color);
        }
    } else {
        int error = delta_x - (delta_y >> 1);      // error may go below zero
        while (y1 != y2) {
            if (error >= 0) {
                if (error || (iy > 0)) {
                    x1 += ix;
                    error -= delta_y;
                }                           // else do nothing
            }                              // else do nothing
            y1 += iy;
            error += delta_x;  
            plot(x1, y1, color);
        }
    }
}

int PRGM_GetKey() {
    unsigned char buffer[12];
    PRGM_GetKey_OS( buffer );
    return ( buffer[1] & 0x0F ) * 10 + ( ( buffer[2] & 0xF0 ) >> 4 );
}

