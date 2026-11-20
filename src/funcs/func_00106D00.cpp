struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162.
struct Object_00107FE0 {
    void func_00108080(int kind, int flag, int first, int second);
};

// For an id from 0x115e to 0x1162 whose object exists: its func_00108080(1, 0, first, second).
void func_00106D00(unsigned int id, int first, int second)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            target->func_00108080(1, 0, first, second);
        }
    }
}
