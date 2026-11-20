struct Target_0007D8E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Holder_0007D8E0 {
    Target_0007D8E0 *first;
    Target_0007D8E0 *second;
    int unknown_08;
    Target_0007D8E0 *target;
};

struct Object_0007C250 {
    char unknown_00[0x7c];
    Holder_0007D8E0 *holder;

    void func_0007D8B0();
};

// Handler (at 0x20D3F8, next to func_0007D8E0): calls slot 5 of the holder's first and second targets with (0, 0).
void Object_0007C250::func_0007D8B0()
{
    holder->first->slot5(0, 0);
    holder->second->slot5(0, 0);
}
