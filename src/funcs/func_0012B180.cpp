struct Game {
    void *func_000128C0(int id);
};

struct Object_00043700 {
    int func_00043700();
};

struct Object_00120420 {
    char unknown_000[0x1c8];
    int mode;
    int step;
};

// The class whose table is at 0x1DA350 (destructor 0x127E60).
struct Object_00127E60 {
    char unknown_00[0x44];
    int value_44;
    char unknown_48[8];
    int value_50;

    void func_0012A640();
    void func_0012B180();
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern int *data_00227DE8[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// By the mode of object 0x1de2 (+0x1c8): in mode 3, runs func_0012A640 and draws text value_50 + 8 of the
// language's table in data_00227DE8 at (68, 376), unless +0x44 is 3 and the object's step (+0x1cc) is 8; in mode
// 2, runs func_0012A640 and draws text value_50 at (54, 370), unless +0x44 is 4, or 3 with step 7.
void Object_00127E60::func_0012B180()
{
    Object_00120420 *menu = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    switch (menu->mode) {
    case 3: {
        func_0012A640();
        int index = value_50 + 8;
        if (value_44 == 3) {
            if (menu->step != 8) {
                func_0003D610(68.0f, 376.0f, 1.0f, 0xffffffff, 0.8f, 0.8f,
                              data_00227DE8[data_001FC724.func_00043700()][index]);
            }
        } else {
            func_0003D610(68.0f, 376.0f, 1.0f, 0xffffffff, 0.8f, 0.8f,
                          data_00227DE8[data_001FC724.func_00043700()][index]);
        }
        break;
    }
    case 2:
        func_0012A640();
        if ((value_44 != 3 || menu->step != 7) && value_44 != 4) {
            int index = value_50;
            func_0003D610(54.0f, 370.0f, 1.0f, 0xffffffff, 0.8f, 0.8f,
                          data_00227DE8[data_001FC724.func_00043700()][index]);
        }
        break;
    }
}
