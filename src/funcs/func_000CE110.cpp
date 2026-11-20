struct Game {
    void *func_000128C0(int id);
};

struct Object_000607B0 {
    void func_00060810(int handle);
};

extern Game *data_0022FCE0;

// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, func_000CF010, ...).
struct Object_000CE220 {
    char unknown_00[8];
    int state;
    char unknown_0c[4];
    int timer;
    char unknown_14[0x30];
    unsigned int value_44;
    char unknown_48[0x4c];
    int value_94;
    char unknown_98[0x90];
    int id;
    char unknown_12c[8];
    int handle;

    void func_000CE110();
};

// A state handler: while 0x44 is set, 180 frames of the timer clear it and make object 0xe8 drop the handle at
// 0x134 (func_00060810), which is unset; once the object whose id is at 0x128 is gone, state 14, 0x94 = 10 and the
// timer cleared.
void Object_000CE220::func_000CE110()
{
    if (value_44 > 0 && ++timer > 180) {
        value_44 = 0;
        if (handle >= 0) {
            Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (target) {
                target->func_00060810(handle);
            }
            handle = -1;
        }
    }
    if (!data_0022FCE0->func_000128C0(id)) {
        state = 14;
        value_94 = 10;
        timer = 0;
    }
}
