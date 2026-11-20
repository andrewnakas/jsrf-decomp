struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000265A0 {
    char unknown_00[0x44];
    int unknown_0044;
};

// Returns the field at +0x44 of object 7.
int func_00025680()
{
    return ((Object_000265A0 *)data_0022FCE0->func_000128C0(7))->unknown_0044;
}
