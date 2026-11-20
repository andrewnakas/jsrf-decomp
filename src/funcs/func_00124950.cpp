// Object 0x1de2.
struct Scene_00124950 {
    char unknown_000[0x224];
    int index;
};

struct Object_00043700 {
    int func_00043700();
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00120420 {
    void func_00124950(float alpha);
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern int data_00227170[];
extern int data_00226F40[];

void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Draws the text for object 0x1de2's index at (240, 172), white with the given alpha (opaque from 1.0): from the
// table at data_00226F40 at 0.8 x 0.8 when func_00043700 reports 0, from data_00227170 at 0.9 x 0.8 for 1 to 5.
// Never reads this.
void Object_00120420::func_00124950(float alpha)
{
    Scene_00124950 *scene = (Scene_00124950 *)data_0022FCE0->func_000128C0(0x1de2);
    unsigned int color;
    if (alpha >= 1.0f) {
        color = 0xffffffff;
    } else {
        color = ((int)(alpha * 255.0f) << 24) | 0xffffff;
    }
    switch ((unsigned int)data_001FC724.func_00043700()) {
    case 0:
        func_0003D610(240.0f, 172.0f, 1.0f, color, 0.8f, 0.8f, data_00226F40[scene->index]);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        func_0003D610(240.0f, 172.0f, 1.0f, color, 0.9f, 0.8f, data_00227170[scene->index]);
        break;
    }
}
