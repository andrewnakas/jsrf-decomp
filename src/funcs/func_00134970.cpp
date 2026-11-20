// Member slot of the 0x1DE828 class (0x38 bytes); the port's id at +0x10.
struct Slot_00134970 {
    char unknown_00[0x10];
    int id;
    char unknown_14[0x24];
};

// Two rows of five per slot (0x30 bytes).
struct Link_00134970 {
    int first[6];
    int second[6];
};

struct Object_00134880 {
    char unknown_000[0x58];
    unsigned long devices;
    char unknown_05c[0x10];
    unsigned int values[8];
    int ready;
    char unknown_090[0x8c];
    unsigned char first[0x118];
    char unknown_234[0x318];
    Slot_00134970 slots[4];
    Link_00134970 links[4];

    int func_00136300(int mode);
    void func_00134970();
};

extern "C" void *memset(void *destination, int value, unsigned int size);

// The device type the XPP library's func_001BD5FF counts (it reports one bit per port); it lies in a code section.
extern char data_001BC860[];
unsigned long __stdcall func_001BD5FF(void *type);

// Member of the 0x1DE828 class (called by func_00134AB0 and its slot 1): keeps the ports holding a device
// (func_001BD5FF) at +0x58, clears the eight words at +0x6c and the 0x118 bytes at +0x11c, keeps func_00136300(8)
// at +0x8c (0 when no byte of +0x11c is set afterwards), and fills each slot's two rows of five at +0x62c with -1
// and with the slot's number (-1 when the slot has no id).
void Object_00134880::func_00134970()
{
    devices = func_001BD5FF((void *)data_001BC860);
    for (int k = 0; k < 8; k++) {
        values[k] = 0;
    }
    memset(first, 0, sizeof(first));
    ready = func_00136300(8);
    int i;
    for (i = 0; i < 0x118; i++) {
        if (first[i]) {
            break;
        }
    }
    if (i == 0x118) {
        ready = 0;
    }
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 5; k++) {
            links[j].first[k] = -1;
            if (slots[j].id < 0) {
                links[j].second[k] = -1;
            } else {
                links[j].second[k] = j;
            }
        }
    }
}
