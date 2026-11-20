struct Guid;
struct Unknown;

// MFile2's class id and the interface 0x1E3F44.
extern const Guid data_001E3F74;
extern const Guid data_001E3F44;

// The interface 0x1E3F44 (the class whose table is at 0x1E4020 gives it out; slot 3 initialises the object).
struct Interface_001E3F44 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument1, void *argument2, void *argument3, void *argument4, void *argument5);
};

// Creates an object of a class and asks it for an interface (0x1765B0, the module's CoCreateInstance).
long __stdcall func_001765B0(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates an MFile2 object for the interface 0x1E3F44 and initialises it with the five arguments (slot 3); lets go
// of it again when that fails. 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_00176630(void *argument1, void *argument2, void *argument3, void *argument4, void *argument5,
                             Interface_001E3F44 **object, Unknown *outer)
{
    long result;
    if (object) {
        result = func_001765B0(data_001E3F74, outer, 1, data_001E3F44, (void **)object);
        if (result >= 0) {
            result = (*object)->slot3(argument1, argument2, argument3, argument4, argument5);
            if (result < 0 && *object) {
                (*object)->slot2();
                *object = 0;
            }
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
