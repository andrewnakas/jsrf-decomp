/* const: 0x200000 */
struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F880 {
    char unknown_000[0x8b4];
    unsigned int mode;
    char unknown_8b8[0xc];
    int unknown_8c4;
};

// The player object (func_000A0F10 calls this with its own `this`).
struct Object_000A1C50 : Node {
    char unknown_0000[0x1170];
    int value_1170;
    int value_1174;

    // func_0007F880, inlined here.
    int func_0007F880()
    {
        Parent_0007F880 *parent = (Parent_0007F880 *)func_00011BD0();
        if (value_1170 <= 0 && value_1174 <= 0) {
            return parent->unknown_8c4;
        }
        return 0;
    }
    int func_0007FAA0();
};

// 1 when bit 21 of func_0007F880's word is set and the parent's mode (+0x8b4) is not 3 to 5; else 0.
int Object_000A1C50::func_0007FAA0()
{
    if ((func_0007F880() & 0x200000) != 0) {
        unsigned int mode = ((Parent_0007F880 *)func_00011BD0())->mode;
        if (mode < 3 || mode > 5) {
            return 1;
        }
    }
    return 0;
}
