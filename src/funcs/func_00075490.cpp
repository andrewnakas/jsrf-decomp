struct Object_00039BE0 {
    int func_00039DB0(int group, int index);
};

extern Object_00039BE0 data_001EFFB0;

// An entry of the table at +0xc0 (0x10 bytes): its index, two flags and a state (-1 until set).
struct Entry_00075490 {
    int index;
    int unknown_04;
    int unlocked;
    int state;
};

// The part at +0xb4: a flag at +0x28.
struct Part_00075490 {
    char unknown_00[0x28];
    int any;
};

// The class whose table is at 0x1CCCD8 (constructor 0x75A30, destructor 0x74D60).
struct Object_00074D60 {
    char unknown_00[0xb4];
    Part_00075490 *part;
    char unknown_b8[8];
    Entry_00075490 *entries;

    void func_00075490();
};

// Called by the constructor: numbers the 13 entries at +0xc0 (state -1); each whose flag 0x180 + i of group 3 is set
// (func_00039DB0 of 0x1EFFB0) is unlocked (and marks the part at +0xb4), its state then being flag 0x1a0 + i.
void Object_00074D60::func_00075490()
{
    if (entries) {
        for (int i = 0; i < 13; i++) {
            entries[i].index = i;
            entries[i].unknown_04 = 0;
            entries[i].unlocked = 0;
            entries[i].state = -1;
        }
        for (int j = 0; j < 13; j++) {
            if (data_001EFFB0.func_00039DB0(3, 0x180 + j)) {
                part->any = 1;
                entries[j].unlocked = 1;
                if (data_001EFFB0.func_00039DB0(3, 0x1a0 + j)) {
                    entries[j].state = 1;
                } else {
                    entries[j].state = 0;
                }
            }
        }
    }
}
