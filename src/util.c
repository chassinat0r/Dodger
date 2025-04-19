#include "util.h"

bool sprites_colliding(HitBox hb1, HitBox hb2) {
    bool collides_vertically = (hb1.left >= hb2.left && hb1.left <= hb2.right) || (hb1.left <= hb2.left && hb1.right >= hb2.left);
    bool collides_horizontally = (hb1.top >= hb2.top && hb1.top <= hb2.bottom) || (hb1.top <= hb2.top && hb1.bottom >= hb2.top);
    return collides_vertically && collides_horizontally;
}
