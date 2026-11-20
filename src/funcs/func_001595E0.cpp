struct Item {
    int value;
    char unknown_04[0xc];
    int extra;
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual int __stdcall func_001595E0(Item *item, int *extra);  // slot 15
};

int __stdcall Object_001E1640::func_001595E0(Item *item, int *extra)
{
    if (extra)
        *extra = item->extra;
    return item->value;
}
