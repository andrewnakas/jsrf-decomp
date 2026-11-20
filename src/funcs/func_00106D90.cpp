struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// What object 9 fills in (func_0004D460; 0x118 bytes).
struct Info_0004D460 {
    int values[5];
    char unknown_14[0x104];
};

struct Object_0004D460 {
    void func_0004D460(Info_0004D460 *info);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x16ac];
    unsigned int flags;

    void func_00108280(int kind, int first, int second, int third);
};

// With object 9's info (func_0004D460), for an id from 0x115e to 0x1162 whose object exists: kind 0 with the
// object's flag 0x8000 passes info values 1 and 0, kind 1 with flag 0x4000 values 3 + 4 and 2, to its func_00108280
// (kind 1).
void func_00106D90(unsigned int id, int kind)
{
    Object_0004D460 *stage = (Object_0004D460 *)data_0022FCE0->func_000128C0(9);
    if (stage) {
        Info_0004D460 info;
        stage->func_0004D460(&info);
        Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (id >= 0x115e && id <= 0x1162 && object) {
            switch (kind) {
            case 0:
                if (object->flags & 0x8000) {
                    object->func_00108280(1, info.values[1], info.values[0], 0);
                }
                break;
            case 1:
                if (object->flags & 0x4000) {
                    object->func_00108280(1, info.values[3] + info.values[4], info.values[2], 0);
                }
                break;
            }
        }
    }
}
