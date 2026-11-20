// Object 0x1de2.
struct Scene_00121880 {
    char unknown_0000[0x4158];
    float alpha;
};

struct Object_00043700 {
    int func_00043700();
};

struct Game {
    void *func_000128C0(int id);
};

// The class whose table is at 0x1D9118 (destructor 0x1217D0).
struct Object_001217D0 {
    char unknown_00[0x44];
    int kind;

    void func_00121880();
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern int *data_00227BF0[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws the hint for the kind at +0x44 at (48, 378), white with object 0x1de2's alpha (opaque from 1.0): text 0 of
// the language's list at data_00227BF0 for kinds 1, 3, 4, 5, 9, 10 and 12, text 1 for kind 8, nothing otherwise.
void Object_001217D0::func_00121880()
{
    Scene_00121880 *scene = (Scene_00121880 *)data_0022FCE0->func_000128C0(0x1de2);
    if (kind) {
        unsigned int color;
        if (scene->alpha >= 1.0f) {
            color = 0xffffffff;
        } else {
            color = ((int)(scene->alpha * 255.0f) << 24) | 0xffffff;
        }
        switch (kind) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 9:
        case 10:
        case 12:
            func_0003D610(48.0f, 378.0f, 1.0f, color, 0.8f, 0.8f,
                          data_00227BF0[data_001FC724.func_00043700()][0]);
            break;
        case 8:
            func_0003D610(48.0f, 378.0f, 1.0f, color, 0.8f, 0.8f,
                          data_00227BF0[data_001FC724.func_00043700()][1]);
            break;
        }
    }
}
