// The device type the XPP library's func_001BD5FF counts (it reports one bit per port); it lies in a code section.
extern char data_001BC860[];

unsigned long __stdcall func_001BD5FF(void *type);

// The class whose table is at 0x1CCA80 (constructor 0x70E30, destructor 0x71040).
struct Object_00071040 {
    char unknown_000[0x500];
    int used[4];

    void func_0006FD50(int value);
    int func_00071090();
};

// Called by slot 1 (0x71CB0): when a port that is in use (+0x500) has lost its device (func_001BD5FF's mask), hands
// the port to func_0006FD50 and returns 0; else 1.
int Object_00071040::func_00071090()
{
    unsigned long mask = func_001BD5FF((void *)data_001BC860);
    int present[4];
    present[0] = mask & 1;
    present[1] = mask & 2;
    present[2] = mask & 4;
    present[3] = mask & 8;
    for (unsigned int i = 0; i < 4; i++) {
        if (used[i] && !present[i]) {
            func_0006FD50(i);
            return 0;
        }
    }
    return 1;
}
