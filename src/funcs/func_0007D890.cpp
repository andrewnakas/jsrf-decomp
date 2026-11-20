struct Target_0007D8E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Holder_0007D8E0 {
    char unknown_00[0xc];
    Target_0007D8E0 *target;
};

struct Object_0007C250 {
    char unknown_00[0x5c];
    int unknown_5c;
    char unknown_60[0x1c];
    Holder_0007D8E0 *holder;
    int *unknown_80;

    void func_0007D890();
};

// Handler (at 0x20D3E4, 0x20D3E8 and 0x20D3F4, next to func_0007D8E0 at 0x20D3FC): calls slot 5 of the target of the holder at +0x7c with the
// word the pointer at +0x80 refers to and the word at +0x5c (func_0007D8E0 passes 0, 0).
void Object_0007C250::func_0007D890()
{
    holder->target->slot5(*unknown_80, unknown_5c);
}
