// The device type the XPP library's func_001BD5FF counts (it reports one bit per port); it lies in a code section.
extern char data_001BC860[];

extern unsigned int data_0025ED2C;

unsigned long __stdcall func_001BD5FF(void *type);

struct Object_001379E0 {
    char unknown_000[0x64];
    int value_64;
    char unknown_068[0x230];
    unsigned int ports[4];
    unsigned int count;
    char unknown_2ac[0x4];
    int state;

    int func_00139430();
};

// Records which of the four ports hold a device (func_001BD5FF) and how many; 1 when fewer than last time (with
// none left, state 10 and +0x64 cleared), else 0. The count is kept in data_0025ED2C for the next call.
int Object_001379E0::func_00139430()
{
    int result = 0;
    unsigned long mask = func_001BD5FF((void *)data_001BC860);
    ports[0] = mask & 1;
    ports[1] = mask & 2;
    ports[2] = mask & 4;
    ports[3] = mask & 8;
    count = 0;
    for (int i = 0; i < 4; i++) {
        if (ports[i]) {
            count++;
        }
    }
    if (count < data_0025ED2C) {
        if (count == 0) {
            state = 0xa;
            value_64 = 0;
        }
        result = 1;
    }
    data_0025ED2C = count;
    return result;
}
