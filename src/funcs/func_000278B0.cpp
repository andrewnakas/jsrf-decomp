struct Object_000265A0 {
    char unknown_0000[0x179c];
    int unknown_179c;
    void *unknown_17a0[5];
    int unknown_17b4;
    char unknown_17b8[0x8];
    int unknown_17c0;

    void *func_000278B0(int unused, int kind, int index);
};

// Handler 21 of the table at 0x1EC200: while +0x17b4 is set, the address of +0x179c (kind 0) or +0x17c0 (kind 1),
// or pointer `index` from +0x17a0 (kind 2); else 0.
void *Object_000265A0::func_000278B0(int, int kind, int index)
{
    if (unknown_17b4) {
        switch (kind) {
        case 0:
            return &unknown_179c;
        case 1:
            return &unknown_17c0;
        case 2:
            return unknown_17a0[index];
        }
    }
    return 0;
}
