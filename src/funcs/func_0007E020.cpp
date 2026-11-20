struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

struct Object_0007E020 {
    virtual ~Object_0007E020();
    virtual void slot1();
    virtual void slot2();
    virtual void func_0007E020(int argument);

};

// Slot 3 of the tables at 0x1CCB28 and 0x1CCF38.
void Object_0007E020::func_0007E020(int)
{
    data_0022FCE0->func_00012750();
}
