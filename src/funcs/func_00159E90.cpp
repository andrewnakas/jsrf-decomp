extern "C" void *memcpy(void *destination, const void *source, unsigned int size);
void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);
int __stdcall func_0014A85B(void *handle);

// The list of objects at data_00265120 (data_00265124 entries).
extern void **data_00265120;
extern unsigned int data_00265124;

// Puts the object in the first free entry of the list, growing the list by 0x200 entries (func_0014A83E with 0x40,
// the old list freed with func_0014A85B) while it is full. 1 when there is no list, E_OUTOFMEMORY when it cannot
// grow. The first argument is not used (the counterpart of 0x159F30).
long __stdcall func_00159E90(void *link, void *object)
{
    if (data_00265124) {
        for (;;) {
            for (unsigned int i = 0; i < data_00265124; i++) {
                if (data_00265120[i] == 0) {
                    data_00265120[i] = object;
                    return 0;
                }
            }
            void **list = (void **)func_0014A83E(0x40, (data_00265124 + 0x200) * sizeof(void *));
            memcpy(list, data_00265120, data_00265124 * sizeof(void *));
            func_0014A85B(data_00265120);
            data_00265120 = list;
            data_00265124 += 0x200;
            if (!list)
                return 0x8007000e;
        }
    }
    return 1;
}
