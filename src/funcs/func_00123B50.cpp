struct Item_00123B50 {
    char unknown_00[0x60];
    int value;
};

struct Kind_00226AB0 {
    int slot;
    char unknown_04[0xc];
};

struct Object_00120420 {
    char unknown_0000[0x10ec];
    int first;
    int second;
    int third;
    char unknown_10f8[0x15b4];
    int values[0x45];
    char unknown_27c0[4];
    int shown[0x45];
    char unknown_28d8[4];
    Item_00123B50 *items[0x45];
    char unknown_29f0[0x7ac];
    unsigned char marks[0x46];

    void func_00123B50();
};

extern int data_00226750[];
extern Kind_00226AB0 data_00226AB0[];

// Member of object 0x1de2's class: marks entries 0 to 0x45, gives items 1 to 0x44 their values from +0x26ac, then
// gives the item of the slot the current choice picks (data_00226750 and data_00226AB0) its value from +0x27c4.
void Object_00120420::func_00123B50()
{
    marks[0] = 1;
    marks[0x45] = 1;
    for (int i = 1; i <= 0x44; i++) {
        items[i]->value = values[i];
        marks[i] = 1;
    }
    int slot = data_00226AB0[data_00226750[(first * 4 + third) * 18 + second]].slot;
    if (slot >= 1 && slot <= 0x44) {
        items[slot]->value = shown[slot];
    }
}
