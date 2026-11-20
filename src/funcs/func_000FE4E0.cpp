struct Game {
    int func_000127E0(int kind);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1165.
struct Object_000FE190 {
    void func_000FDFB0(int kind, int first, int second, int crowded);
};

// Maps the kinds 0xa6, 0xa7 and 0xac to 0x5e, 0x5f and 0x60, then passes the kind and both values to
// func_000FDFB0 of object 0x1165, when it exists, with whether func_000127E0(2) counts 20 or more.
void func_000FE4E0(int kind, int first, int second)
{
    int crowded = data_0022FCE0->func_000127E0(2) >= 20u;
    if (kind == 0xa6) {
        kind = 0x5e;
    } else if (kind == 0xa7) {
        kind = 0x5f;
    } else if (kind == 0xac) {
        kind = 0x60;
    }
    Object_000FE190 *object = (Object_000FE190 *)data_0022FCE0->func_000128C0(0x1165);
    if (object) {
        object->func_000FDFB0(kind, first, second, crowded);
    }
}
