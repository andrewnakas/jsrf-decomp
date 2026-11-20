// The table at +0xc48: from +0x1c, where the slots of each part begin.
struct Parts_0006A1B0 {
    char unknown_00[0x1c];
    unsigned int first[1];
};

struct Slot_0006A1B0 {
    void *data;
    int unknown_04;
};

struct Object_0006A1B0 {
    char unknown_000[0x18];
    Slot_0006A1B0 *slots;
    char unknown_01c[0xc2c];
    Parts_0006A1B0 *parts;

    int func_0006A1B0(int part);
};

// 1 when every slot of a part has its data, else 0.
int Object_0006A1B0::func_0006A1B0(int part)
{
    for (unsigned int i = parts->first[part]; i < parts->first[part + 1]; i++) {
        if (!slots[i].data) {
            return 0;
        }
    }
    return 1;
}
