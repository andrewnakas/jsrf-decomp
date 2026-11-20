struct Object_00120420 {
    void func_0012E240(int first, int second);
};

struct Game {
    void *func_000128C0(int id);
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
__declspec(noreturn) void __stdcall func_00147E4E(unsigned long code);

// A thread procedure: passes game values 0x1c6 and 0x1c7 to func_0012E240 of object 0x1de2, sets game value
// 0x1c9 and ends the thread through func_00147E4E.
unsigned long __stdcall func_00127F70(void *)
{
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    int first = data_0022FCE0->func_000127E0(0x1c6);
    int second = data_0022FCE0->func_000127E0(0x1c7);
    scene->func_0012E240(first, second);
    data_0022FCE0->func_000127C0(0x1c9, 1);
    func_00147E4E(0);
}
