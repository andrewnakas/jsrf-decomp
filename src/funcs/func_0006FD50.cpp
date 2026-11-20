struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003E430 {
    void func_0003E430(int mode);
};

// The class whose table is at 0x1CCA80.
struct Object_00071040 {
    char unknown_000[0x98];
    int state;
    char unknown_09c[0x430];
    int unknown_4cc;
    int previous;
    char unknown_4d4[0x10];
    int ids[4];

    void func_0006FD50(int value);
};

// Called by 0x71090 (from slot 1, 0x71CB0): keeps `value` at +0x4cc and the state at +0x4d0, moves to state 10 and
// passes 2 to func_0003E430 of the four objects whose ids are at +0x4e4.
void Object_00071040::func_0006FD50(int value)
{
    unknown_4cc = value;
    previous = state;
    state = 10;
    for (unsigned int i = 0; i < 4; i++) {
        Object_0003E430 *object = (Object_0003E430 *)data_0022FCE0->func_000128C0(ids[i]);
        object->func_0003E430(2);
    }
}
