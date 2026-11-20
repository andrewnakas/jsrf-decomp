struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_0004FC40 {
    char unknown_000[0x88c];
    int *ids;
    unsigned int count;

    unsigned int func_0004FC40();
};

// The index of the game's value 0x1ac among the ids at +0x88c, or 0 when it is not there.
unsigned int Object_0004FC40::func_0004FC40()
{
    int id = data_0022FCE0->func_000127E0(0x1ac);
    for (unsigned int i = 0; i < count; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return 0;
}
