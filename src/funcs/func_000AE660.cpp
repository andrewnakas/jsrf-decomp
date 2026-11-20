struct Game {
    void *func_000128C0(int id);
};

struct Target_000AE660 {
    char unknown_00[0xa4];
    int value_a4;
};

struct Object_000AE660 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void func_000AE660(int argument);
};

extern Game *data_0022FCE0;

// Virtual (slot 6 of the vtables at data_001CD608, data_001CD658 and data_001CD6A0). Passes the argument
// to virtual slot 3 unless object 0xeb exists with its field at 0xa4 clear.
void Object_000AE660::func_000AE660(int argument)
{
    Target_000AE660 *target = (Target_000AE660 *)data_0022FCE0->func_000128C0(0xeb);
    if (!target || target->value_a4) {
        slot3(argument);
    }
}
