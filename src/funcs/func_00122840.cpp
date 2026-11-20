// A placed piece (0x30 bytes): its offsets and turn.
struct Piece_00122840 {
    int x;
    int y;
    int angle;
    char unknown_0c[0x24];
};

struct Object_00120420 {
    char unknown_0000[0xda4];
    int choice;
    char unknown_0da8[0x18];
    Piece_00122840 pieces[14];
    char unknown_1060[0x18];
    int hue;
    int saturation;
    int value;

    void func_00122840();
};

extern unsigned int data_00251EE4;
extern float data_00251EF4;
extern float data_00251EF8;
extern float data_00251F18;

// With no piece chosen (+0xda4 below 0): buttons 0x200 and 0x100 step the value at +0x1080 down and up and the stick
// (past 0.7 either way, with its strength at data_00251F18 0.7 or more) steps the saturation at +0x107c (x) and the
// hue at +0x1078 (y), each wrapping within 0..359. With a piece chosen: the buttons turn it by 0x16c and the stick
// (strength 0.2 or more) moves it by 182 per unit.
void Object_00120420::func_00122840()
{
    if (choice < 0) {
        if (data_00251EE4 & 0x200) {
            if (--value < 0) {
                value = 359;
            }
        } else if (data_00251EE4 & 0x100) {
            if (++value > 359) {
                value = 0;
            }
        }
    }
    if (choice < 0) {
        if (!(data_00251F18 < 0.7f)) {
            float x = -data_00251EF4;
            float y = -data_00251EF8;
            float across = x >= 0.7f ? 1.0f : (x <= -0.7f ? -1.0f : 0.0f);
            float down = y >= 0.7f ? 1.0f : (y <= -0.7f ? -1.0f : 0.0f);
            hue += (int)down;
            saturation += (int)across;
            if (hue < 0) {
                hue = 359;
            }
            if (hue > 359) {
                hue = 0;
            }
            if (saturation < 0) {
                saturation = 359;
            }
            if (saturation > 359) {
                saturation = 0;
            }
        }
    } else {
        if (data_00251EE4 & 0x200) {
            pieces[choice].angle -= 0x16c;
        } else if (data_00251EE4 & 0x100) {
            pieces[choice].angle += 0x16c;
        }
        if (!(data_00251F18 < 0.2)) {
            float x = -data_00251EF4;
            float y = -data_00251EF8;
            pieces[choice].x += (int)(y * 182.04445f);
            pieces[choice].y += (int)(x * 182.04445f);
        }
    }
}
