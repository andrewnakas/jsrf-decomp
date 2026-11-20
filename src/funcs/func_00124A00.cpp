struct Game {
    void *func_000128C0(int id);
};

struct Object_00043700 {
    int func_00043700();
};

struct Object_00120420 {
    char unknown_0000[0xb44];
    int entry;
    char unknown_0b48[0x3610];
    float fade;
};

// The class whose table is at 0x1DA2C0 (destructor 0x124700).
struct Object_00124700 {
    char unknown_00[0x44];
    int message;

    void func_00124A00();
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern int *data_002280D0[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Member of the class whose table is at 0x1DA2C0 (called by its slot 3, 0x124BD0): draws message +0x44 at (48,
// 378) in white, faded by the float at +0x4158 of object 0x1de2 while it is below 1: messages 2, 9 and 21 are
// text `entry` (+0xb44 of that object) of the language's table in data_002280D0, 3, 10, 11, 12 and 18 its text 7,
// 4 its text 8; others draw nothing.
void Object_00124700::func_00124A00()
{
    Object_00120420 *menu = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    if (message) {
        unsigned int color;
        if (menu->fade >= 1.0f) {
            color = 0xffffffff;
        } else {
            color = (int)(menu->fade * 255.0f) << 24 | 0xffffff;
        }
        switch (message) {
        case 2:
        case 9:
        case 21:
            func_0003D610(48.0f, 378.0f, 1.0f, color, 0.8f, 0.8f,
                          data_002280D0[data_001FC724.func_00043700()][menu->entry]);
            break;
        case 3:
        case 10:
        case 11:
        case 12:
        case 18:
            func_0003D610(48.0f, 378.0f, 1.0f, color, 0.8f, 0.8f, data_002280D0[data_001FC724.func_00043700()][7]);
            break;
        case 4:
            func_0003D610(48.0f, 378.0f, 1.0f, color, 0.8f, 0.8f, data_002280D0[data_001FC724.func_00043700()][8]);
            break;
        }
    }
}
