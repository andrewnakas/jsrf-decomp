extern "C" void *memset(void *to, int value, unsigned int size);

struct Interface_001E18C4;
struct Interface_00251D64;
struct Unknown;

long __stdcall func_0015FCC0(void *argument1, void *argument2, void *argument3, Interface_001E18C4 **input,
                             Unknown *outer);
unsigned long __stdcall func_001BD5FF(void *type);

extern Interface_00251D64 *data_00251D64;

// The device type the XPP library's func_001BD5FF counts (controllers); it lies in a code section.
extern char data_001BC860[];

// A controller port of the context (0xb0 bytes).
struct Port_0005F250 {
    char unknown_00[0x20];
    int handle;
    char unknown_24[0x8c];
};

// The context at 0x251D7C.
struct Context_00251D7C {
    virtual ~Context_00251D7C();

    void *unknown_004;
    void *unknown_008;
    int unknown_00c;
    int unknown_010;
    Port_0005F250 ports[4];
    unsigned long devices;

    long func_0005F250();
};

// Creates the input interface into 0x251D64 (func_0015FCC0 with the words at +8 and +4) and, when that works,
// keeps the connected devices of that type (func_001BD5FF) at +0x2d4; clears the four ports with no handle (-1).
// Returns the creation's result.
long Context_00251D7C::func_0005F250()
{
    long result = func_0015FCC0(unknown_008, unknown_004, 0, (Interface_001E18C4 **)&data_00251D64, 0);
    if (result >= 0) {
        devices = func_001BD5FF(data_001BC860);
    }
    memset(ports, 0, sizeof(ports));
    for (unsigned int i = 0; i < 4; i++) {
        ports[i].handle = -1;
    }
    return result;
}
