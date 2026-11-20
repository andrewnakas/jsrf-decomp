struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Entry_0006DB80;

struct Object_0006DB80 {
    Entry_0006DB80 *func_0006DB80(int key);
};

extern Object_0006DB80 data_00251F78;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    void func_00107C00(int value, int first, int kind);
    void func_00107D10(int value, int kind);
    void func_00107D70(int value, int fast, int kind);
};

// An object with an id from 0x4c to 0x4f; the id of its Object_00107FE0 is at 0x23c.
struct Holder_00106FF0 {
    char unknown_000[0x23c];
    int target;
};

// For an id from 0x4c to 0x4f whose object and its Object_00107FE0 (id at 0x23c) exist, and a key that data_00251F78
// knows (func_0006DB80), by `which`: 0 func_00107C00 (key, entry, 0), 1 and 2 func_00107D70 (key, fast 1 or 0, 0),
// 3 func_00107D10 (key, 0).
void func_00106FF0(unsigned int id, int key, int which)
{
    if (id >= 0x4c && id <= 0x4f) {
        Holder_00106FF0 *holder = (Holder_00106FF0 *)data_0022FCE0->func_000128C0(id);
        if (holder) {
            Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(holder->target);
            if (object) {
                Entry_0006DB80 *entry = data_00251F78.func_0006DB80(key);
                if (entry) {
                    switch (which) {
                    case 0:
                        object->func_00107C00(key, (int)entry, 0);
                        break;
                    case 1:
                        object->func_00107D70(key, 1, 0);
                        break;
                    case 2:
                        object->func_00107D70(key, 0, 0);
                        break;
                    case 3:
                        object->func_00107D10(key, 0);
                        break;
                    }
                }
            }
        }
    }
}
