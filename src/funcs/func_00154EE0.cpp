extern "C" void *memcpy(void *destination, const void *source, unsigned int size);
void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);
int __stdcall func_0014A85B(void *handle);

// The device's list of resources (data_002650E8 entries at data_002650E4).
extern void **data_002650E4;
extern unsigned int data_002650E8;

// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    long func_00154EE0(void *resource);
};

// Puts the resource in the first free entry of the list, growing the list by 0x200 entries (func_0014A83E with
// 0x40, the old list freed with func_0014A85B) while it is full. 1 when there is no list, E_OUTOFMEMORY when it
// cannot grow.
long Object_001E0F00::func_00154EE0(void *resource)
{
    if (data_002650E8) {
        for (;;) {
            for (unsigned int i = 0; i < data_002650E8; i++) {
                if (data_002650E4[i] == 0) {
                    data_002650E4[i] = resource;
                    return 0;
                }
            }
            void **list = (void **)func_0014A83E(0x40, (data_002650E8 + 0x200) * sizeof(void *));
            memcpy(list, data_002650E4, data_002650E8 * sizeof(void *));
            func_0014A85B(data_002650E4);
            data_002650E4 = list;
            data_002650E8 += 0x200;
            if (!list)
                return 0x8007000e;
        }
    }
    return 1;
}
