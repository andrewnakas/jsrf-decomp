struct Guid;
struct Unknown;

// MEvent's class id and the interface 0x1E40DC.
extern const Guid data_001E40FC;
extern const Guid data_001E40DC;

// The interface 0x1E40DC (the class whose table is at 0x1E4130 gives it out; slot 3 initialises the object).
struct Interface_001E40DC {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument1, void *argument2, void *argument3, void *argument4);
};

// Creates an object of a class and asks it for an interface (0x179690, the module's CoCreateInstance).
long __stdcall func_00179690(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates an MEvent object for the interface 0x1E40DC and initialises it with the four arguments (slot 3); lets go
// of it again when that fails. 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_00179770(void *argument1, void *argument2, void *argument3, void *argument4,
                             Interface_001E40DC **object, Unknown *outer)
{
    long result;
    if (object) {
        result = func_00179690(data_001E40FC, outer, 1, data_001E40DC, (void **)object);
        if (result >= 0) {
            result = (*object)->slot3(argument1, argument2, argument3, argument4);
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
