struct Game {
    void func_000127C0(int index, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00107190(unsigned int handle, int value);

// The player's camera node: a handle at +0x23c.
struct Camera_0007FE70 {
    char unknown_000[0x23c];
    unsigned int handle;
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0xc98];
    int camera;
    char unknown_c9c[0x2fc];
    int unknown_f98;
    int unknown_f9c;
    int unknown_fa0;
    int unknown_fa4;
    char unknown_fa8[0xc];
    int unknown_fb4;

    void func_0007FE70(int value, int percent, int mode);
};

// Each argument that is not negative is taken: the value (at most +0xfa4) goes to +0xfa0 and to func_00107190 with
// the camera node's handle; the percentage of +0xf9c goes to +0xf98; the mode to +0xfb4 (0 as -1). A percentage of
// exactly 100 also sets the game's entries 0x151 to 0x170 to -1.
void Object_000A1C50::func_0007FE70(int value, int percent, int mode)
{
    if (value >= 0) {
        unknown_fa0 = value;
        if (value > unknown_fa4) {
            unknown_fa0 = unknown_fa4;
        }
        Camera_0007FE70 *node = (Camera_0007FE70 *)data_0022FCE0->func_000128C0(camera);
        if (node) {
            func_00107190(node->handle, unknown_fa0);
        }
    }
    if (percent >= 0) {
        unknown_f98 = unknown_f9c * percent / 100;
    }
    if (mode >= 0) {
        if (mode == 0) {
            unknown_fb4 = -1;
        } else {
            unknown_fb4 = mode;
        }
    }
    if (percent == 100) {
        for (unsigned int i = 0; i < 0x20; i++) {
            data_0022FCE0->func_000127C0(0x151 + i, -1);
        }
    }
}
