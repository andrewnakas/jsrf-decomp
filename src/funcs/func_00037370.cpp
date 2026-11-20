int func_00118BA0(unsigned int id);
void func_00036F10(int index);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// One of the 25 entries at 0x230DD0 (func_00036820 reads `busy`).
struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int busy;
};

extern Entry_00230DD0 data_00230DD0[];

struct Object_000607B0 {
    char unknown_00[0x4c];
    int unknown_4c;
};

struct Object_000265A0 {
    char unknown_0000[0x16b8];
    int unknown_16b8;

    void func_00037370(int index);
};

// Handler 14 of the table at 0x1EC288: while the 0x230DD0 entry of +0x16b8 is busy, func_00118BA0 (0x34),
// func_00036F10 for `index` and for 6, and 1 into +0x4c of object 0xe8 if it exists.
void Object_000265A0::func_00037370(int index)
{
    if (data_00230DD0[unknown_16b8].busy) {
        func_00118BA0(0x34);
        func_00036F10(index);
        func_00036F10(6);
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object)
            object->unknown_4c = 1;
    }
}
