extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

// Allocates size bytes (func_00145A2F with 0x3000 and 4) and clears them.
void *__cdecl func_00150EA0(unsigned int size)
{
    void *memory = func_00145A2F(0, size, 0x3000, 4);
    if (memory)
        memset(memory, 0, size);
    return memory;
}
