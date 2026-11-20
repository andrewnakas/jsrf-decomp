struct Interface_001380C0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

struct Object_001379E0 {
    char unknown_000[0x2cc];
    Interface_001380C0 *entries[58];
    int count;

    void func_001380C0();
};

// Calls slot 2 of each of the 58 interfaces at +0x2cc that is set, clears it, and clears the count after them.
void Object_001379E0::func_001380C0()
{
    for (int i = 0; i < 58; i++) {
        if (entries[i]) {
            entries[i]->slot2();
            entries[i] = 0;
        }
    }
    count = 0;
}
