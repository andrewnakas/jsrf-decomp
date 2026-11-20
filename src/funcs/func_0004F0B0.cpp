struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004F0B0 {
    char unknown_00[0x48];
    unsigned int unknown_48;
};

struct Object_0004EF90 {
    char unknown_00[0x44];
    unsigned int state;

    void func_0004F0B0();
};

// State handler 5 of the table at 0x1FA008: goes to state 6 once object 10 exists with its word at +0x48 at least 2.
void Object_0004EF90::func_0004F0B0()
{
    Object_0004F0B0 *object = (Object_0004F0B0 *)data_0022FCE0->func_000128C0(0xa);
    if (object && object->unknown_48 >= 2) {
        state = 6;
    }
}
