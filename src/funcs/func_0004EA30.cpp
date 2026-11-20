struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004EA30 {
    char unknown_00[0x48];
    unsigned int unknown_48;
};

// Says whether object 9 exists and its word at +0x48 is at least 2.
int func_0004EA30()
{
    Object_0004EA30 *object = (Object_0004EA30 *)data_0022FCE0->func_000128C0(9);
    if (object && object->unknown_48 >= 2) {
        return 1;
    }
    return 0;
}
