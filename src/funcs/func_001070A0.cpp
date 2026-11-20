struct Game {
    void *func_000128C0(int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    void func_00107C00(int value, int first, int kind);
    void func_00107D10(int value, int kind);
    void func_00107D70(int value, int fast, int kind);
};

extern Game *data_0022FCE0;

// For an id from 0x115e to 0x1162 whose object exists, by `which`: 0 func_00107C00 (value, first, 1), 1 and 2
// func_00107D70 (value, fast 1 or 0, kind 1), 3 func_00107D10 (value, kind 1).
void func_001070A0(unsigned int id, int value, int first, int which)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (object) {
            switch (which) {
            case 0:
                object->func_00107C00(value, first, 1);
                break;
            case 1:
                object->func_00107D70(value, 1, 1);
                break;
            case 2:
                object->func_00107D70(value, 0, 1);
                break;
            case 3:
                object->func_00107D10(value, 1);
                break;
            }
        }
    }
}
