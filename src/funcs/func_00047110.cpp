struct Slot_00047080 {
    int unknown_00[2];
    int unknown_08;
    int unknown_0c;
    char unknown_10[0x40];
};

// What func_00047080 fills in: nine slots of 0x50 bytes.
struct Info_00047080 {
    Slot_00047080 slots[9];
};

struct Object_00047110 {
    int func_00046FD0(int index, Slot_00047080 *slot);
    int func_00047080(Info_00047080 *info);
    int func_000470C0(Info_00047080 *info);
    int func_00047110(void *buffer);
};

// Whether any of the nine slots has its count at +0xc above 0 (into a buffer of its own when none is given).
int Object_00047110::func_00047110(void *buffer)
{
    Info_00047080 local;
    Info_00047080 *info = (Info_00047080 *)buffer;
    if (!info) {
        info = &local;
    }
    func_00047080(info);
    for (int i = 0; i < 9; i++) {
        if (info->slots[i].unknown_0c > 0) {
            return 1;
        }
    }
    return 0;
}
