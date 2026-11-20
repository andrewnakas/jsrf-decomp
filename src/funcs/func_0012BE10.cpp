struct Object_00070850 {
    void func_00070960(int index);
};

// The pad's held and pressed buttons.
extern unsigned int data_00251EE4;
extern unsigned int data_00251EE8;

// The palette: 16 x 8 colours of three bytes.
extern unsigned char data_002280E8[];

struct Object_00120420 {
    char unknown_0000[0xb68];
    int red;
    int green;
    int blue;
    char unknown_0b74[0x28];
    float cursor_y;
    float cursor_x;
    char unknown_0ba4[4];
    unsigned int held_left;
    unsigned int held_right;
    unsigned int held_up;
    unsigned int held_down;

    void func_0012BE10();
};

// Moves the palette cursor of the GRAFFITI editor: counts how long each pad direction (0x1000, 0x2000, 0x4000,
// 0x8000) is held; a press, or a hold past 25 ticks (which then repeats every 5), steps the cursor at +0xb9c (0 to 15,
// by 0x4000 / 0x8000) or the one at +0xba0 (0 to 7, by 0x1000 / 0x2000), wrapping round, with sound 3
// (func_00070960). Then takes the colour under the cursor from data_002280E8 into +0xb68.
void Object_00120420::func_0012BE10()
{
    if (data_00251EE4 & 0x1000) {
        held_left++;
    } else {
        held_left = 0;
    }
    if (data_00251EE4 & 0x2000) {
        held_right++;
    } else {
        held_right = 0;
    }
    if (data_00251EE4 & 0x4000) {
        held_up++;
    } else {
        held_up = 0;
    }
    if (data_00251EE4 & 0x8000) {
        held_down++;
    } else {
        held_down = 0;
    }
    if ((data_00251EE8 & 0x4000) || held_up > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_up > 25) {
            held_up = 20;
        }
        cursor_y -= 1.0f;
        if (cursor_y < 0.0f) {
            cursor_y = 15.0f;
        }
    }
    if ((data_00251EE8 & 0x8000) || held_down > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_down > 25) {
            held_down = 20;
        }
        cursor_y += 1.0f;
        if (cursor_y > 15.0f) {
            cursor_y = 0.0f;
        }
    }
    if ((data_00251EE8 & 0x1000) || held_left > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_left > 25) {
            held_left = 20;
        }
        cursor_x -= 1.0f;
        if (cursor_x < 0.0f) {
            cursor_x = 7.0f;
        }
    }
    if ((data_00251EE8 & 0x2000) || held_right > 25) {
        ((Object_00070850 *)this)->func_00070960(3);
        if (held_right > 25) {
            held_right = 20;
        }
        cursor_x += 1.0f;
        if (cursor_x > 7.0f) {
            cursor_x = 0.0f;
        }
    }
    int index = (int)((cursor_x * 16.0f + cursor_y) * 3.0f);
    red = data_002280E8[index];
    green = data_002280E8[index + 1];
    blue = data_002280E8[index + 2];
}
