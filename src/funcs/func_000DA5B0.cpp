// One of the sixty slots at 0x64 (16 bytes); its state is 0, 1 or 2 (free) and 4.
struct Slot_000DA5B0 {
    char unknown_00[0xc];
    unsigned int state;
};

// The child of Node whose table is at 0x1CE658 (constructor func_000DA1E0).
struct Object_000DA3E0 {
    char unknown_000[0x44];
    int full;
    char unknown_048[0x14];
    unsigned int end;
    unsigned int start;
    Slot_000DA5B0 slots[60];

    int func_000DA5B0();
};

// Finds the slot with the lowest state below 2 between the start (0x60) and end (0x5c) indices, wrapping at 60;
// when there is none, turns the free (2) slots back to 0 and looks again. A slot found at 0 goes to 1, one at 1 to
// 4; with none at all, 0x44 is set. Returns the slot found, or -1. Called by func_000DA710.
int Object_000DA3E0::func_000DA5B0()
{
    int found = -1;
    unsigned int lowest = 2;
    unsigned int i;
    for (i = start; i != end;) {
        unsigned int state = slots[i].state;
        if (state < lowest) {
            found = i;
            lowest = state;
        }
        if (++i >= 60) {
            i = 0;
        }
    }
    if (lowest == 2) {
        for (i = start; i != end;) {
            if (slots[i].state == 2) {
                slots[i].state = 0;
            }
            unsigned int state = slots[i].state;
            if (state < lowest) {
                found = i;
                lowest = state;
            }
            if (++i >= 60) {
                i = 0;
            }
        }
    }
    switch (lowest) {
    case 0:
        slots[found].state++;
        break;
    case 1:
        slots[found].state = 4;
        break;
    default:
        full = 1;
        break;
    }
    return found;
}
