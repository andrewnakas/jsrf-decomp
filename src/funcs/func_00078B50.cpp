/* sym: ??0Object_000780F0@@QAE@PAUNode@@HIHH@Z = 0x00078520 */
/* sym: ??0Object_00079B50@@QAE@PAUNode@@HIH@Z = 0x0007A8B0 */
/* const: 0x10003 */
struct Node;
struct Object_0004ABA0;

struct Game {
    void func_000126D0(int value);
    void func_00012730(int value);
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

// The menu node (0x45c bytes; table 0x1CCD18, destructor 0x780F0).
struct Object_000780F0 {
    Object_000780F0(Node *owner, int id, unsigned int flags, int mode, int value);

    char unknown_000[0x45c];
};

// Object 0x1163's node (0x144 bytes; table 0x1CCDE8).
struct Object_00079B50 {
    Object_00079B50(Node *owner, int id, unsigned int flags, int value);

    char unknown_000[0x144];
};

// Unless the game's entry 0x1b4 is set, opens a menu node 0x1167 under `object` by entry 0x1b3: with the top bit in
// mode 1 or 0 (by bit 0), with bit 30 in mode 2 (each then func_000126D0(1)), with bit 29 object 0x1163's node (then
// func_00012730(1)). Returns whether it opened one.
int func_00078B50(Object_0004ABA0 *object, int value)
{
    if (data_0022FCE0->func_000127E0(0x1b4)) {
        return 0;
    }
    unsigned int flags = data_0022FCE0->func_000127E0(0x1b3);
    if (flags & 0x80000000) {
        if (flags & 1) {
            new Object_000780F0((Node *)object, 0x1167, 0x10003, 1, value);
        } else {
            new Object_000780F0((Node *)object, 0x1167, 0x10003, 0, value);
        }
        data_0022FCE0->func_000126D0(1);
        return 1;
    }
    if (flags & 0x40000000) {
        new Object_000780F0((Node *)object, 0x1167, 0x10003, 2, value);
        data_0022FCE0->func_000126D0(1);
        return 1;
    }
    if (flags & 0x20000000) {
        new Object_00079B50((Node *)object, 0x1167, 0x10003, 0);
        data_0022FCE0->func_00012730(1);
        return 1;
    }
    return 0;
}
