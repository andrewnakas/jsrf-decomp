struct Guid;
struct Unknown;

// MGameSound8's class id and interface id.
extern const Guid data_001E395C;
extern const Guid data_001E394C;

// MGameSound8's first interface: the table at 0x1E3A70 (slot 3 initialises the object).
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument);
};

// Creates an object of a class and asks it for an interface (0x168050, the module's CoCreateInstance).
long __stdcall func_00168050(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates an MGameSound8 and initialises it with the argument (slot 3); lets go of it again when that fails.
// 0x80070057 (E_INVALIDARG) without a place for it.
long __stdcall func_001680D0(void *argument, FirstInterface **sound, Unknown *outer)
{
    long result;
    if (sound) {
        result = func_00168050(data_001E395C, outer, 1, data_001E394C, (void **)sound);
        if (result >= 0) {
            result = (*sound)->slot3(argument);
            if (result < 0 && *sound) {
                (*sound)->slot2();
                *sound = 0;
            }
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
