struct Guid;
struct Unknown;

// MGameInput8's class id and interface id.
extern const Guid data_001E18E4;
extern const Guid data_001E18C4;

// MGameInput8's interface 0x1E18C4: slot 3 initialises the object, slot 5 is called after it with two zeros.
struct Interface_001E18C4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument1, void *argument2, void *argument3);
    virtual void slot4();
    virtual long __stdcall slot5(void *argument1, void *argument2);
};

// Creates an object of a class and asks it for an interface (0x15FC40, the module's CoCreateInstance).
long __stdcall func_0015FC40(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates an MGameInput8, initialises it with the three arguments (slot 3) and then calls its slot 5 with two zeros;
// lets go of it again when either fails. 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_0015FCC0(void *argument1, void *argument2, void *argument3, Interface_001E18C4 **input,
                             Unknown *outer)
{
    long result;
    if (input) {
        result = func_0015FC40(data_001E18E4, outer, 1, data_001E18C4, (void **)input);
        if (result >= 0) {
            result = (*input)->slot3(argument1, argument2, argument3);
            if (result >= 0)
                result = (*input)->slot5(0, 0);
            if (result < 0 && *input) {
                (*input)->slot2();
                *input = 0;
            }
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
