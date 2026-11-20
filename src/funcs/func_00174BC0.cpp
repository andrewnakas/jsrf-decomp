struct Guid;
struct Unknown;

// MemStream's class id and interface id.
extern const Guid data_001E3E3C;
extern const Guid data_001E3E2C;

// MemStream's first interface: the table at 0x1E3EA8 (slot 3 opens the stream).
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(void *argument1, void *argument2);
};

// Creates an object of a class and asks it for an interface (0x174B40, the module's CoCreateInstance).
long __stdcall func_00174B40(const Guid &classId, Unknown *outer, unsigned long context, const Guid &id,
                             void **object);

// Creates a MemStream and opens it with the two arguments (slot 3); lets go of it again when that fails (0x178830
// calls it).
long __stdcall func_00174BC0(void *argument1, void *argument2, FirstInterface **stream, Unknown *outer)
{
    long result = func_00174B40(data_001E3E3C, outer, 1, data_001E3E2C, (void **)stream);
    if (result < 0)
        return result;
    result = (*stream)->slot3(argument1, argument2);
    if (result < 0 && *stream) {
        (*stream)->slot2();
        *stream = 0;
    }
    return result;
}
