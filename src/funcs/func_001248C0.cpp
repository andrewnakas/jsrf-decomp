struct Scene_00124910 {
    char unknown_0000[0xb44];
    int mode;
    char unknown_0b48[0x26bf];
    unsigned char marks[0x1c];
};

struct Object_00039BE0 {
    int func_0003A2B0(int row, int column);
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00120420 {
    void func_001248C0();
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;

// Unless object 0x1de2 is in mode 5, marks at +0x3207 each of the 28 columns that func_0003A2B0 of
// data_001EFFB0 reports set in the row of its mode. Never reads this.
void Object_00120420::func_001248C0()
{
    Scene_00124910 *scene = (Scene_00124910 *)data_0022FCE0->func_000128C0(0x1de2);
    if (scene->mode != 5) {
        for (int i = 0; i < 0x1c; i++) {
            if (data_001EFFB0.func_0003A2B0(scene->mode, i) == 1) {
                scene->marks[i] = 1;
            }
        }
    }
}
