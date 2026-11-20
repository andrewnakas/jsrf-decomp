struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    char unknown_04[0x40];
};

// The four controller ports (64 bytes each): the buttons held, as a word.
struct Entry_00251DE8 {
    union {
        unsigned int buttons;
        struct {
            unsigned int a : 1;
            unsigned int b : 1;
            unsigned int x : 1;
            unsigned int y : 1;
        } bits;
    };
    char unknown_04[0x3c];
};

// The word 4 bytes before each port of data_00251DE8: the buttons held long enough to repeat.
struct Entry_00251DE4 {
    unsigned int repeat;
    char unknown_04[0x3c];
};

struct Object_001197F0 : Node {
    virtual ~Object_001197F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    char unknown_44[0x18];
    int locked;
    unsigned int port;
    unsigned int buttons;
    unsigned int delay;

    int func_00119800();
};

extern Entry_00251DE8 data_00251DE8[];
extern Entry_00251DE4 data_00251DE4[];

// The device type the XPP library's func_001BD5FF counts (it reports one bit per port); it lies in a code section.
extern char data_001BC860[];
unsigned long __stdcall func_001BD5FF(void *type);

// Returns 0 when the port at +0x60 holds no device (func_001BD5FF). Otherwise clears the button flags at +0x64 and,
// unless +0x5c is set, fills them from the port: 5 from bits 0 or 2, 0xa from bits 1 or 3, 0x10-0x80 from bits
// 0x1000-0x8000 (with a delay of 15 at +0x68) and, while no delay runs, from the same bits of the repeat word
// (delay 10), then counts the delay down. Returns 1.
int Object_001197F0::func_00119800()
{
    unsigned long mask = func_001BD5FF((void *)data_001BC860);
    unsigned long ports[4];
    ports[0] = mask & 1;
    ports[1] = mask & 2;
    ports[2] = mask & 4;
    ports[3] = mask & 8;
    if (!ports[port]) {
        return 0;
    }
    buttons = 0;
    if (!locked) {
        if (data_00251DE8[port].bits.a || data_00251DE8[port].bits.x) {
            buttons = 5;
        }
        if (data_00251DE8[port].bits.b || data_00251DE8[port].bits.y) {
            buttons |= 0xa;
        }
        if (data_00251DE8[port].buttons & 0x1000) {
            buttons |= 0x10;
            delay = 15;
        }
        if (data_00251DE8[port].buttons & 0x2000) {
            buttons |= 0x20;
            delay = 15;
        }
        if (data_00251DE8[port].buttons & 0x4000) {
            buttons |= 0x40;
            delay = 15;
        }
        if (data_00251DE8[port].buttons & 0x8000) {
            buttons |= 0x80;
            delay = 15;
        }
        if ((data_00251DE4[port].repeat & 0x1000) && !delay) {
            buttons |= 0x10;
            delay = 10;
        }
        if ((data_00251DE4[port].repeat & 0x2000) && !delay) {
            buttons |= 0x20;
            delay = 10;
        }
        if ((data_00251DE4[port].repeat & 0x4000) && !delay) {
            buttons |= 0x40;
            delay = 10;
        }
        if ((data_00251DE4[port].repeat & 0x8000) && !delay) {
            buttons |= 0x80;
            delay = 10;
        }
        if (delay > 0) {
            delay--;
        }
    }
    return 1;
}
