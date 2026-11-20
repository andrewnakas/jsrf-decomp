struct Game {
    int func_000127E0(int id);
};

extern Game *data_0022FCE0;

void func_00106B90(unsigned int handle, int mask, int value);

struct Object_000A4D80 {
    char unknown_000[0x23c];
    unsigned int handle;

    void func_000A4B80();
};

// Through func_00106B90 on the handle at 0x23c: clears everything but setting 0x19e's bits (func_000127E0), then
// sets those bits.
void Object_000A4D80::func_000A4B80()
{
    func_00106B90(handle, ~data_0022FCE0->func_000127E0(0x19e), 0);
    func_00106B90(handle, data_0022FCE0->func_000127E0(0x19e), 1);
}
