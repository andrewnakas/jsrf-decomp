struct Object_000A63F0 {
    void func_000A63F0();
};

struct Game {
    void func_00012760();
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004ABA0 {
    char unknown_0000[0x1038];
    int unknown_1038;

    void func_0004D880();
};

// Runs the game's func_00012760, then func_000A63F0 on each of objects 0xc to 0x2b that exists, and sets +0x1038.
void Object_0004ABA0::func_0004D880()
{
    data_0022FCE0->func_00012760();
    for (int id = 0xc; id <= 0x2b; id++) {
        Object_000A63F0 *object = (Object_000A63F0 *)data_0022FCE0->func_000128C0(id);
        if (object) {
            object->func_000A63F0();
        }
    }
    unknown_1038 = 1;
}
