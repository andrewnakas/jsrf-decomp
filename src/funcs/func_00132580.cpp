struct Interface_00132580 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

extern Interface_00132580 *data_0025C300[5];

// The class of object 0x1de2.
struct Object_00120420 {
    // Member of object 0x1de2's class that never reads `this` (its callers load ecx with the object): releases the
// five interfaces in data_0025C300 (slot 2) and clears them.
void Object_00120420::func_00132580();
};

// Member of object 0x1de2's class that never reads `this` (its callers load ecx with the object): releases the
// five interfaces in data_0025C300 (slot 2) and clears them.
void Object_00120420::func_00132580()
{
    for (int i = 0; i < 5; i++) {
        if (data_0025C300[i]) {
            data_0025C300[i]->slot2();
            data_0025C300[i] = 0;
        }
    }
}
