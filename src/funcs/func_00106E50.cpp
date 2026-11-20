struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162.
struct Object_00107FE0 {
    char unknown_0000[0x16c4];
    int value_16c4;
    int value_16c8;
    int value_16cc;
    int value_16d0;
    int value_16d4;
    char unknown_16d8[4];
    int value_16dc;
    int value_16e0;

    void func_001077D0(unsigned int kind);
};

// For an id from 0x115e to 0x1162 whose object exists: stores the values the kind uses (kind 0: two at 0x16dc,
// kind 1: one at 0x16c4, kind 2: three at 0x16cc, kind 3: one at 0x16c8), then calls its func_001077D0(kind).
void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *target = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (target) {
            switch (kind) {
            case 0:
                target->value_16dc = first;
                target->value_16e0 = second;
                break;
            case 1:
                target->value_16c4 = first;
                break;
            case 2:
                target->value_16cc = first;
                target->value_16d0 = second;
                target->value_16d4 = third;
                break;
            case 3:
                target->value_16c8 = first;
                break;
            }
            target->func_001077D0(kind);
        }
    }
}
