struct Game {
    int func_000127E0(int index);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object with id 9; a frame count at 0x1048.
struct Clock_0010F410 {
    char unknown_0000[0x1048];
    unsigned int frames;
};

// A direct child of Node (constructor func_0010E8F0, table 0x1D23F0, destructor func_0010EAB0); its slot 1
// (func_0010EB10) runs the handlers of data_002216E0 by the mode at 0x160.
struct Object_0010E8F0 {
    char unknown_000[0x84];
    float seconds;
    char unknown_088[0xc4];
    float value_14c;
    char unknown_150[8];
    unsigned int color;
    char unknown_15c[4];
    int mode;

    void func_0010F410();
};

// Entries 2 and 3 of data_002216E0: 40 at 0x14c when game value 0xc is above 1; the seconds at 0x84 from the frame
// count of object 9 (0 without it); in mode 2 the color at 0x158 is white above 30 seconds, else red.
void Object_0010E8F0::func_0010F410()
{
    if ((unsigned int)data_0022FCE0->func_000127E0(0xc) > 1) {
        value_14c = 40.0f;
    }
    Clock_0010F410 *clock = (Clock_0010F410 *)data_0022FCE0->func_000128C0(9);
    if (clock) {
        seconds = clock->frames * 0.016666668f;
    } else {
        seconds = 0.0f;
    }
    if (mode == 2) {
        if (seconds > 30.0f) {
            color = 0xffffffff;
        } else {
            color = 0xffff0000;
        }
    }
}
