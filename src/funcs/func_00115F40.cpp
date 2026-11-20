struct Object_00115E20 {
    virtual ~Object_00115E20();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int argument);
    virtual void slot7();
    virtual void slot8();
    virtual void func_00115F40(int message);

    char unknown_04[0x40];
    int value_44;
    char unknown_48[0xc];
    int first;
    int second;
};

void func_0003D5D0(int first, int second, float scale, int value, float x, float y, int last);

// Slot 9 of the table at 0x1D3770 (also slot 3 of the table at 0x1D07F8): for messages 0, 3, 5 and 8 calls
// func_0003D5D0 with the words at +0x54 and +0x58, 1.1, -1, 1, 1 and the word at +0x44.
void Object_00115E20::func_00115F40(int message)
{
    switch (message) {
    case 0:
    case 3:
    case 5:
    case 8:
        func_0003D5D0(first, second, 1.1f, -1, 1.0f, 1.0f, value_44);
        break;
    }
}
