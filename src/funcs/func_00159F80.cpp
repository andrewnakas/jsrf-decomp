void *__stdcall func_0014A83E(unsigned long flags, unsigned long size);

struct Source {
    int unknown_00;
    void *data;
};

long __stdcall func_0014CB20(Source *source);
long __stdcall func_001BB780(Source *source);

struct Interface_00265110 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual Source *__stdcall slot8(int kind);
};

extern Interface_00265110 *data_00265110;
extern void *data_00265114;
extern void *data_00265118;
extern void *data_0026511C;
extern void **data_00265120;
extern unsigned int data_00265124;

// Frees the list at data_00265120.
void __stdcall func_00159E20(void *link);

// Sets the engine up on the interface: hands its sources 1 and 2 (its slot 8) to func_0014CB20 and func_001BB780,
// makes the 0x200-entry list at data_00265120 and keeps the interface, the value and the two sources' data.
// E_OUTOFMEMORY (after func_00159E20) when the list cannot be made.
long __stdcall func_00159F80(void *link, Interface_00265110 *object, void *value)
{
    long result = func_0014CB20(object->slot8(1));
    if (result >= 0) {
        result = func_001BB780(object->slot8(2));
        if (result >= 0) {
            void **list = (void **)func_0014A83E(0x40, 0x200 * sizeof(void *));
            if (list) {
                data_00265120 = list;
                data_00265124 = 0x200;
                data_00265110 = object;
                data_00265114 = value;
                data_00265118 = object->slot8(1)->data;
                data_0026511C = object->slot8(2)->data;
                return 0;
            }
            result = 0x8007000e;
            func_00159E20(link);
        }
    }
    return result;
}
