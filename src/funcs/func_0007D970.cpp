// A controller slot (0x40 bytes): whether it is connected.
struct Slot_001116E0 {
    int busy;
    char unknown_04[0x3c];
};

extern Slot_001116E0 data_00251E1C[4];

// The class whose table is at 0x1CCEF8 (constructor 0x7D5D0, destructor 0x7D680).
struct Object_0007C250 {
    char unknown_00[0x78];
    unsigned int connected;

    int func_0007D970();
};

// Keeps bit i of +0x78 equal to whether controller slot i is in use; 1 when any slot came in since the last call.
int Object_0007C250::func_0007D970()
{
    int added = 0;
    for (int i = 0; i < 4; i++) {
        if (data_00251E1C[i].busy) {
            if (!(connected & (1 << i))) {
                added = 1;
            }
            connected |= 1 << i;
        } else {
            connected &= ~(1 << i);
        }
    }
    return added;
}
