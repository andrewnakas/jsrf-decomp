int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
long __stdcall func_00159F30(void *unused, void *object);

struct Voice {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();  // Release
};

// The class whose table is at 0x1E1610 (11 slots, 0x20 bytes; Release 0x159420, created by 0x159450).
struct Object_001E1610 {
    virtual long __stdcall func_00159180(const void *iid, void **object);  // slot 0

    Voice *voice;
    unsigned long value_08;
    void *memory;
    unsigned long size;
};

// Takes the object apart: frees its memory (func_00145A5D with 0x8000), releases its voice and takes it off the
// list at data_00265120 (func_00159F30).
void __stdcall func_001592D0(Object_001E1610 *object)
{
    if (object->memory) {
        func_00145A5D(object->memory, 0, 0x8000);
        object->memory = 0;
        object->size = 0;
    }
    if (object->voice) {
        object->voice->slot2();
        object->voice = 0;
        object->value_08 = 0;
    }
    func_00159F30(&object->voice, object);
}
