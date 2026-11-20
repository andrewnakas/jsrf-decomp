struct Guid;

// One of the object descriptions at +0x24 (0x13c bytes, the size of DirectInput's DIDEVICEOBJECTINSTANCEA): the type
// flags are at +0x18.
struct ObjectInstance {
    char unknown_00[0x18];
    unsigned long type;
    char unknown_1c[0x120];
};

// The callback slot 4 takes: nonzero to go on.
typedef int (__stdcall *ObjectCallback)(ObjectInstance *instance, void *context);

// The class whose table is at 0x1E3828 (33 slots; the destructor is the last).
struct Object_001E3828 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_00167110(void *argument1, void *argument2, void *argument3);

    char unknown_04[0x10];
    void *device;
    void *buffer;
    unsigned long last;
    unsigned int count;
    ObjectInstance *objects;
};

// Slot 4: calls the callback with the context for each of the `count` (+0x20) object descriptions at +0x24 whose type
// shares a flag with the third argument, until the callback returns 0 (DirectInput's EnumObjects). 0x80070057
// (E_INVALIDARG) without a callback, 0x800401F0 (not initialised) while +0x14 is null.
long __stdcall Object_001E3828::func_00167110(void *argument1, void *argument2, void *argument3)
{
    if (device) {
        if (argument1) {
            for (unsigned int i = 0; i < count; ++i) {
                ObjectInstance *object = &objects[i];
                if ((unsigned long)argument3 & object->type) {
                    if (!((ObjectCallback)argument1)(object, argument2))
                        break;
                }
            }
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
