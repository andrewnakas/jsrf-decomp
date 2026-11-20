struct Game {
    void func_000127C0(int index, int value);
};

struct Object_00120420 {
    int func_0012F2B0(int state);
};

extern Game *data_0022FCE0;
unsigned long __stdcall func_0012F220(void *parameter);
void *__stdcall func_00147F53(void *attributes, unsigned long stackSize, unsigned long(__stdcall *start)(void *),
                              void *parameter, unsigned long flags, unsigned long *id);

// Clears game value 0x1c8 and starts func_0012F220 in a thread of its own; returns 1. Callers pass a state
// (0x12985a pushes 8) that it does not read, and it never reads this.
int Object_00120420::func_0012F2B0(int)
{
    unsigned long id;
    data_0022FCE0->func_000127C0(0x1c8, 0);
    func_00147F53(0, 0, func_0012F220, 0, 0, &id);
    return 1;
}
