extern int data_00265168;
extern void *data_0026516C;
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_001E17E0;

// One object of the class at 0x1E17E0 fewer (the count at 0x265168); the last one frees the memory at 0x26516C
// (func_00145A5D with 0x8000).
void __stdcall func_0015F9A0(Object_001E17E0 *object)
{
    if (--data_00265168 == 0 && data_0026516C) {
        func_00145A5D(data_0026516C, 0, 0x8000);
        data_0026516C = 0;
    }
}
