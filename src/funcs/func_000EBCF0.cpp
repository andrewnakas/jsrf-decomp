void func_001BA9C0();
void func_001BAA50();

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1770.
struct Object_00157F10 {
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

// A part embedded in the objects of func_000E7F50 (at 0x30) and func_000ECB50 (at 0xbc): a key at 0x3c and three
// more at 0x40.
struct Object_000EBB80 {
    char unknown_00[0x3c];
    int key;
    int keys[3];

    void func_000EBCF0(Object_00047470 *model);
};

// Inside a pushed matrix: with a key at 0x3c, frame 0x12 of the model and func_000C1770 on the key; then frame 0 and
// func_000C1770 on each of the three keys at 0x40 that is set.
void Object_000EBB80::func_000EBCF0(Object_00047470 *model)
{
    func_001BA9C0();
    if (key != -1) {
        model->func_000480C0(0x12);
        data_00257CE8->func_000C1770(key);
    }
    model->func_000480C0(0);
    for (int i = 0; i < 3; i++) {
        if (keys[i] != -1) {
            data_00257CE8->func_000C1770(keys[i]);
        }
    }
    func_001BAA50();
}
