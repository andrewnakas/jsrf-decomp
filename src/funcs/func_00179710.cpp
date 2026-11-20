struct Guid;
struct Unknown;

// MEvent's class id and the interface 0x1E40EC.
extern const Guid data_001E40FC;
extern const Guid data_001E40EC;

// The interface 0x1E40EC (the class whose table is at 0x1E410C gives it out; slot 3 initialises the object).
struct EventInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument1, void *argument2);
};

// Creates an object of a class and asks it for an interface (0x179690, the module's CoCreateInstance).
long __stdcall func_00179690(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates an MEvent object for the interface 0x1E40EC and initialises it with the two arguments (slot 3); lets go of
// it again when that fails. 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_00179710(void *argument1, void *argument2, EventInterface **event, Unknown *outer)
{
    long result;
    if (event) {
        result = func_00179690(data_001E40FC, outer, 1, data_001E40EC, (void **)event);
        if (result >= 0) {
            result = (*event)->slot3(argument1, argument2);
            if (result < 0 && *event) {
                (*event)->slot2();
                *event = 0;
            }
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
