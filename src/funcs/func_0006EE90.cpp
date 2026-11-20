/* const: 0x200000 */
extern "C" void *memset(void *to, int value, unsigned int size);

// What func_00147532 hands the next program (0xc00 bytes): its kind first.
struct Launch_0006EFF0 {
    unsigned int kind;
    char unknown_004[0xbfc];
};

unsigned long __stdcall func_00147532(const char *path, Launch_0006EFF0 *launch);

// The four controller ports (64 bytes each): flags (1: connected) and a word at +0x34.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x33];
    int unknown_34;
    char unknown_38[8];
};

extern Entry_00251DE8 data_00251DE8[];

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

// Object 0x12b0.
struct Object_0006EC00 : Node {
    char unknown_2c[0x6c];
    unsigned int flags;

    void func_0006EE90();
};

// Whether any of the four ports has one of the flags in `mask`.
inline int AnyPort(unsigned char mask)
{
    return (data_00251DE8[0].flags & mask) || (data_00251DE8[1].flags & mask) || (data_00251DE8[2].flags & mask) ||
           (data_00251DE8[3].flags & mask);
}

// For all four ports: takes the object out when a port has flag 4 and the object flag 0x8000000, a port flag 1 and
// 0x20000000, or a port a word at +0x34 and 0x200000; otherwise, with the top flag and a port with flag 8 or 2,
// starts the next program with kind 2 (func_00147532).
void Object_0006EC00::func_0006EE90()
{
    if (AnyPort(4) && (flags & 0x8000000)) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if (AnyPort(1) && (flags & 0x20000000)) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if (flags & 0x200000) {
        for (int i = 0; i < 4; i++) {
            if (data_00251DE8[i].unknown_34) {
                func_00011BE0(this);
                func_00011C20(child);
                return;
            }
        }
    }
    if (AnyPort(8) && (flags & 0x80000000)) {
        Launch_0006EFF0 launch;
        memset(&launch, 0, sizeof(launch));
        launch.kind = 2;
        func_00147532(0, &launch);
    } else if (AnyPort(2) && (flags & 0x80000000)) {
        Launch_0006EFF0 launch;
        memset(&launch, 0, sizeof(launch));
        launch.kind = 2;
        func_00147532(0, &launch);
    }
}
