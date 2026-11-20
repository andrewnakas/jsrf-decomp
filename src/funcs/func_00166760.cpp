struct Guid;
struct Unknown;

// DirectInput8's class id.
extern const Guid data_001E2178;

// The interface the caller asks for (slot 7 initialises the object, as DirectInput's Initialize does).
struct Interface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(void *instance, unsigned long version);
};

// Creates an object of a class and asks it for an interface (0x1666E0, the module's CoCreateInstance).
long __stdcall func_001666E0(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates a DirectInput8 object for the interface `id` and initialises it with the instance and version (slot 7);
// gives it out with a reference added only when that works, and lets go of the creation reference (the arguments
// are those of DirectInput's DirectInput8Create). 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_00166760(void *instance, unsigned long version, const Guid &id, void **object, void *outer)
{
    long result;
    if (object) {
        Interface *input;
        result = func_001666E0(data_001E2178, (Unknown *)outer, 1, id, (void **)&input);
        if (result >= 0) {
            result = input->slot7(instance, version);
            if (result >= 0) {
                input->slot1();
                *object = input;
            }
            if (input)
                input->slot2();
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
