struct Game {
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    virtual ~Object_00039BE0();

    char unknown_04[0x10];
    unsigned int flags;

    void func_00039CB0(unsigned int index);
};

// Sets one of 32 flags and stores -1 in the game value that goes with it.
void Object_00039BE0::func_00039CB0(unsigned int index)
{
    if (index < 0x20) {
        flags |= 1 << index;
        data_0022FCE0->func_000127C0(index + 0x151, -1);
    }
}
