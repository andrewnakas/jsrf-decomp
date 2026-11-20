struct Target_0007D8F0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Holder_0007D8F0 {
    char unknown_00[0x8];
    Target_0007D8F0 *target;
};

struct Object_0007C250 {
    char unknown_00[0x7c];
    Holder_0007D8F0 *holder;

    void func_0007D8F0();
};

void Object_0007C250::func_0007D8F0()
{
    holder->target->slot5(0, 0);
}
