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

// Fills in the nine slots (func_00046FD0); whether any of them answered more than 0.
int Object_00047110::func_00047080(Info_00047080 *info)
{
    int found = 0;
    for (int i = 0; i < 9; i++) {
        if (func_00046FD0(i, &info->slots[i]) > 0) {
            found = 1;
        }
    }
    return found;
}
