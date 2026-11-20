// The device type the XPP library's func_001BD5FF counts (it reports one bit per port); it lies in a code section.
extern char data_001BC860[];

unsigned long __stdcall func_001BD5FF(void *type);

struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_00134880 {
    char unknown_00[0x5c];
    unsigned int port_5c;

    int func_00134890();
};

// Checks the four ports that game values 0x1C0-0x1C3 mark as in use (unused ones count as present): 1 when each
// holds a device (func_001BD5FF), else 0 with the first empty port at +0x5c.
int Object_00134880::func_00134890()
{
    unsigned long mask = func_001BD5FF((void *)data_001BC860);
    unsigned long ports[4];
    if (data_0022FCE0->func_000127E0(0x1c0)) {
        ports[0] = mask & 1;
    } else {
        ports[0] = 1;
    }
    if (data_0022FCE0->func_000127E0(0x1c1)) {
        ports[1] = mask & 2;
    } else {
        ports[1] = 1;
    }
    if (data_0022FCE0->func_000127E0(0x1c2)) {
        ports[2] = mask & 4;
    } else {
        ports[2] = 1;
    }
    if (data_0022FCE0->func_000127E0(0x1c3)) {
        ports[3] = mask & 8;
    } else {
        ports[3] = 1;
    }
    for (unsigned int i = 0; i < 4; i++) {
        if (!ports[i]) {
            port_5c = i;
            return 0;
        }
    }
    return 1;
}
