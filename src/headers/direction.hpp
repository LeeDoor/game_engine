#pragma once
#define INV_DIR(a) Direction(-(int)a)
//weird numeration for -operator works
enum Direction {
    Up = -2,
    Right = -1,
    None = 0,
    Left,
    Down
};