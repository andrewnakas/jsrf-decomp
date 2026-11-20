struct Part_000338C0 {
    virtual ~Part_000338C0();
};

struct Block_000338C0 {
    int unknown_00;
};

struct Object_000265A0 {
    char unknown_0000[0x17f4];
    Part_000338C0 *parts[3];
    Block_000338C0 *block;
    int unknown_1804;

    void func_000338C0(int argument);
};

// Handler 23 of the table at 0x1EC288: clears +0x1804, deletes the block at +0x1800 and the three parts at +0x17f4
// (virtual destructors) and clears their pointers.
void Object_000265A0::func_000338C0(int)
{
    unknown_1804 = 0;
    if (block) {
        delete block;
        block = 0;
    }
    for (unsigned int i = 0; i < 3; i++) {
        if (parts[i]) {
            delete parts[i];
            parts[i] = 0;
        }
    }
}
