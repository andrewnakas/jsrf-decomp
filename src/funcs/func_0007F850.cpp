struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F850 {
    char unknown_000[0x8bc];
    int unknown_8bc;
};

// The player object.
struct Object_000A1C50 : Node {
    char unknown_0000[0xcc0];
    int unknown_cc0;
    char unknown_0cc4[0x4ac];
    int value_1170;
    int value_1174;

    int func_0007F850();
};

// The parent's word at +0x8bc (func_00011BD0) while neither counter at +0x1170 and +0x1174 is above zero; else the
// player's own word at +0xcc0.
int Object_000A1C50::func_0007F850()
{
    Parent_0007F850 *parent = (Parent_0007F850 *)func_00011BD0();
    if (value_1170 <= 0 && value_1174 <= 0) {
        return parent->unknown_8bc;
    }
    return unknown_cc0;
}
