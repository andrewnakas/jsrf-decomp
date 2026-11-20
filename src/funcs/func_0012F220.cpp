struct Object_00120420 {
    char unknown_000[0x438];
    unsigned __int64 available;
    unsigned __int64 total;
    unsigned __int64 free;
    char unknown_450[0x4be];
    unsigned char cells[0x118];
    unsigned char values[0x118];

    int func_0012DC50(int first, int second, int index);
};

struct Game {
    void *func_000128C0(int id);
    void func_000127C0(int index, int value);
};

extern Game *data_0022FCE0;
int __stdcall func_0014646E(const char *path, unsigned __int64 *available, unsigned __int64 *total,
                            unsigned __int64 *free);
__declspec(noreturn) void __stdcall func_00147E4E(unsigned long code);

// A thread procedure (started by func_0012F2B0): reads the free space of drive U into object 0x1de2, resets its
// 280 cells through func_0012DC50(0x55, 1, i), sets game value 0x1c8 and ends the thread.
unsigned long __stdcall func_0012F220(void *)
{
    Object_00120420 *scene = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    char path[4] = "X:\\";
    path[0] = 'U';
    func_0014646E(path, &scene->available, &scene->total, &scene->free);
    for (int i = 0; i < 0x118; i++) {
        scene->cells[i] = 0;
        scene->values[i] = 0xff;
        scene->func_0012DC50(0x55, 1, i);
    }
    data_0022FCE0->func_000127C0(0x1c8, 1);
    func_00147E4E(0);
}
