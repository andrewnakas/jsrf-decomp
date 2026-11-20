void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);

// Reserves and commits a block of read-write memory.
void *func_00024390(unsigned long size)
{
    return func_00145A2F(0, size, 0x3000, 4);
}
