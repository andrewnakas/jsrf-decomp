struct Game {
    void *func_000128C0(int id);
};

// Object 0x1164.
struct Object_000F7920 {
    char unknown_000[0x44];
    unsigned int flags;
    char unknown_048[0xc4];
    int value_10c;
    char unknown_110[0x10];
    int value_120;
};

extern Game *data_0022FCE0;

// When object 0x1164 exists: clears its 0x10c, keeps the value at 0x120 and sets bit 31 of its flags at 0x44, looking
// it up again for each.
void func_000F7920(int value)
{
    if (data_0022FCE0->func_000128C0(0x1164)) {
        Object_000F7920 *object = (Object_000F7920 *)data_0022FCE0->func_000128C0(0x1164);
        if (object) {
            object->value_10c = 0;
        }
        object = (Object_000F7920 *)data_0022FCE0->func_000128C0(0x1164);
        if (object) {
            object->value_120 = value;
        }
        object = (Object_000F7920 *)data_0022FCE0->func_000128C0(0x1164);
        if (object) {
            object->flags |= 0x80000000;
        }
    }
}
