struct Game {
    void *func_000128C0(int id);
};

struct Object_000FC4A0 {
    int func_000FC4A0(int mode);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020; func_001074B0 sets the 24 ids at 0x44 to -1).
struct Object_00107FE0 {
    char unknown_00[0x44];
    int ids[24];

    void func_00108000(int index, unsigned int mode);
};

extern Game *data_0022FCE0;

// Passes the mode to func_000FC4A0 of the object whose id is entry `index` at 0x44, when it exists; modes 6 and 7
// also clear the entry.
void Object_00107FE0::func_00108000(int index, unsigned int mode)
{
    Object_000FC4A0 *object = (Object_000FC4A0 *)data_0022FCE0->func_000128C0(ids[index]);
    if (object) {
        object->func_000FC4A0(mode);
        if (mode >= 6 && mode <= 7) {
            ids[index] = -1;
        }
    }
}
