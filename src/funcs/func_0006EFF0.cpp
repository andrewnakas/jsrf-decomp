/* const: 0x200000 */
/* const: 0x100000 */
extern "C" void *memset(void *to, int value, unsigned int size);

// What func_00147532 hands the next program (0xc00 bytes): its kind first.
struct Launch_0006EFF0 {
    unsigned int kind;
    char unknown_004[0xbfc];
};

unsigned long __stdcall func_00147532(const char *path, Launch_0006EFF0 *launch);

// The four controller ports (64 bytes each): flags (1: connected) and a word at +0x34.
struct Entry_00251DE8 {
    unsigned int flags;
    char unknown_04[0x30];
    int unknown_34;
    char unknown_38[8];
};

extern Entry_00251DE8 data_00251DE8[];
extern int data_00251F20;

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
    int value;

    void func_0006EFF0();
};

// For the object's port (+0x9c): takes the object out when the port has flag 4 and the object flag 0x8000000, flag 1
// and 0x20000000, or a word at +0x34 and 0x200000 (with 0x100000 the port becomes the one at 0x251F20); otherwise,
// with the top flag and port flag 8 or 2, starts the next program with kind 2 (func_00147532).
void Object_0006EC00::func_0006EFF0()
{
    int port = value;
    unsigned int portFlags = data_00251DE8[port].flags;
    if ((portFlags & 4) && (flags & 0x8000000)) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if ((portFlags & 1) && (flags & 0x20000000)) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if ((flags & 0x200000) && data_00251DE8[port].unknown_34) {
        if (flags & 0x100000) {
            data_00251F20 = port;
        }
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    if ((portFlags & 8) && (flags & 0x80000000)) {
        Launch_0006EFF0 launch;
        memset(&launch, 0, sizeof(launch));
        launch.kind = 2;
        func_00147532(0, &launch);
    } else if ((portFlags & 2) && (flags & 0x80000000)) {
        Launch_0006EFF0 launch;
        memset(&launch, 0, sizeof(launch));
        launch.kind = 2;
        func_00147532(0, &launch);
    }
}
