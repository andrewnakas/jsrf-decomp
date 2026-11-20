struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F820 {
    char unknown_000[0x8c0];
    float unknown_8c0;
};

// The player object.
struct Object_000A1C50 : Node {
    char unknown_0000[0x1170];
    int value_1170;
    int value_1174;

    float func_0007F820();
};

// The parent's float at +0x8c0 (func_00011BD0) while neither counter at +0x1170 and +0x1174 is above zero; else 1.
float Object_000A1C50::func_0007F820()
{
    Parent_0007F820 *parent = (Parent_0007F820 *)func_00011BD0();
    if (value_1170 <= 0 && value_1174 <= 0) {
        return parent->unknown_8c0;
    }
    return 1.0f;
}
