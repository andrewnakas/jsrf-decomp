struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162.
struct Object_00107FE0 {
    void func_001098A0(int first, int second);
};

// Looks the id up first; for an id from 0x115e to 0x1162 whose object exists, its func_001098A0 with both
// values.
void func_00106B90(unsigned int id, int first, int second)
{
    Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
    if (id >= 0x115e && id <= 0x1162 && target) {
        target->func_001098A0(first, second);
    }
}
