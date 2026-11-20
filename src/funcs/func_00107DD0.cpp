struct Entry_0006DB80;

struct Object_0006DB80 {
    Entry_0006DB80 *func_0006DB80(int key);
};

extern Object_0006DB80 data_00251F78;

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

    int func_00107DD0(int id);
};

int Object_00107FE0::func_00107DD0(int id)
{
    for (int i = 0; i < 16; i++) {
        if (entries[i].kind == 0 && entries[i].id == id) {
            if (!data_00251F78.func_0006DB80(entries[i].value)) {
                entries[i].id = -1;
                entries[i].value = -1;
                return 0;
            }
            return 1;
        }
    }
    return 0;
}
