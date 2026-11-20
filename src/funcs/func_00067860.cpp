// A save slot record (0x10 bytes, from +0x18 of the list at +0x678): used flag at +0x4, time at +0x8.
struct Record_000678D0 {
    int unknown_00;
    int used;
    char unknown_08[8];
};

struct List_000678D0 {
    char unknown_00[0x18];
    Record_000678D0 records[3];
};

// What the node keeps of each of the three save slots (0x10 bytes from +0x688).
struct Slot_00067860 {
    int used;
    char unknown_04[0xc];
};

// The node 0x12af (table 0x1CB0F8, constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0x678];
    List_000678D0 *list;
    char unknown_67c[0xc];
    Slot_00067860 slots[3];

    void func_00067860(int mode);
};

// Called by the constructor 0x67B60 and 0x67A40, 0x67E90, 0x68250: mode 0 copies the used flags of the three save
// slot records; mode 1 clears them.
void Object_00067980::func_00067860(int mode)
{
    List_000678D0 *records = list;
    switch (mode) {
    case 0:
        slots[0].used = records->records[0].used;
        slots[1].used = records->records[1].used;
        slots[2].used = records->records[2].used;
        break;
    case 1:
        for (int i = 0; i < 3; i++) {
            slots[i].used = 0;
        }
        break;
    }
}
