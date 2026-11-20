struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0004D790 {
    char unknown_000[0x264];
    int unknown_264;
    char unknown_268[0xd8c];
    unsigned int masks[1];
};

// Says whether object 9 exists, its word at +0x264 is clear and one of the bits is set in the mask an index picks.
int func_0004EB80(int index, unsigned int bits)
{
    Object_0004D790 *object = (Object_0004D790 *)data_0022FCE0->func_000128C0(9);
    if (object && !object->unknown_264 && (object->masks[index] & bits)) {
        return 1;
    }
    return 0;
}
