struct Object_0011EDA0 {
    virtual ~Object_0011EDA0();
    virtual void func_0011EDB0();

    char unknown_04[0xcc];
    unsigned int state;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Slot 1 of the table at 0x1D8F20: looks up object 0x128a (and drops the result), then raises a state below 2 to 3.
void Object_0011EDA0::func_0011EDB0()
{
    data_0022FCE0->func_000128C0(0x128a);
    if (state <= 1) {
        state = 3;
    }
}
