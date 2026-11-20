struct Game {
    void *func_000128C0(int id);
};

struct Object_00106590 {
    void func_00106590(int fast);
};

// An entry of the list at 0xa4: the object with that id was made for (kind, value).
struct Entry_00107D10 {
    int kind;
    int id;
    int value;
    int unknown_c;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_000[0xa4];
    Entry_00107D10 entries[16];

    void func_00107D70(int value, int fast, int kind);
};

extern Game *data_0022FCE0;

// For every entry made for (kind, value) whose object exists: func_00106590(fast) on it.
void Object_00107FE0::func_00107D70(int value, int fast, int kind)
{
    for (int i = 0; i < 16; i++) {
        if (entries[i].kind == kind && entries[i].value == value && entries[i].id != -1) {
            Object_00106590 *object = (Object_00106590 *)data_0022FCE0->func_000128C0(entries[i].id);
            if (object) {
                object->func_00106590(fast);
            }
        }
    }
}
