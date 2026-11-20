struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
    char unknown_00[0x180];
    int unknown_0180;
};

// Returns the field at +0x180 of object 7.
int func_000257B0()
{
    return ((Object_000265A0 *)data_0022FCE0->func_000128C0(7))->unknown_0180;
}
