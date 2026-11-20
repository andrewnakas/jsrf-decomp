struct Node {
    Node *func_00011BD0();
};

struct Parent_0007F880 {
    char unknown_000[0x8c4];
    int unknown_8c4;
};

struct Object_0007F880 : Node {
    char unknown_0000[0x1170];
    int unknown_1170;
    int unknown_1174;

    int func_0007F880();
};

// The parent's word at +0x8c4 (func_00011BD0) while neither counter at +0x1170 and +0x1174 is above zero; else 0.
int Object_0007F880::func_0007F880()
{
    Parent_0007F880 *parent = (Parent_0007F880 *)func_00011BD0();
    if (unknown_1170 <= 0 && unknown_1174 <= 0) {
        return parent->unknown_8c4;
    }
    return 0;
}
