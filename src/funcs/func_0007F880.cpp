struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F880 {
    char unknown_000[0x8c4];
    int unknown_8c4;
};

// The player object (func_0008A4A0 and func_000A0F10 call this with their own `this`).
struct Object_000A1C50 : Node {
    char unknown_0000[0x1170];
    int value_1170;
    int value_1174;

    int func_0007F880();
};

// The parent's word at +0x8c4 (func_00011BD0) while neither counter at +0x1170 and +0x1174 is above zero; else 0.
int Object_000A1C50::func_0007F880()
{
    Parent_0007F880 *parent = (Parent_0007F880 *)func_00011BD0();
    if (value_1170 <= 0 && value_1174 <= 0) {
        return parent->unknown_8c4;
    }
    return 0;
}
