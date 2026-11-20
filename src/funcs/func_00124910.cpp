struct Scene_00124910 {
    char unknown_0000[0x90e];
    unsigned char cells[0x118];
    unsigned char values[0x118];
    char unknown_0b3e[2];
    int row;
    char unknown_0b44[0x26e1];
    unsigned char marks[0x1c];
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00120420 {
    void func_00124910();
};

extern Game *data_0022FCE0;

// Marks at +0x3225 of object 0x1de2 each of the 28 cells that is set in the object's current row of cells.
// Never reads this.
void Object_00120420::func_00124910()
{
    Scene_00124910 *scene = (Scene_00124910 *)data_0022FCE0->func_000128C0(0x1de2);
    int offset = scene->row * 0x1c;
    for (int i = 0; i < 0x1c; i++) {
        if (scene->cells[offset + i]) {
            scene->marks[i] = 1;
        }
    }
}
