extern "C" unsigned int __cdecl strlen(const char *text);

struct Guid;

// The system library's event and error functions.
void *__stdcall func_00145AC5(void *attributes, int manual, int signalled, const char *name);
unsigned long __stdcall func_00146401();

// The name at +0x20 (a std::string: the characters live in the 16-byte buffer while they fit).
struct String {
    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;

    String &func_00160B90(const char *text, unsigned int size);

    String &assign(const char *text)
    {
        return func_00160B90(text, strlen(text));
    }
};

// The class whose table is at 0x1E4130: the one the MEvent factory (0x1E40C4) creates for the interface 0x1E40DC.
struct Object_001E4130 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00179FA0(void *attributes, int manual, int signalled, const char *name);

    char unknown_04[8];
    void *event;
    char unknown_10[0x10];
    String name;
};

// Slot 3: keeps the name (0x160B90) and creates the event (0x145AC5) into +0xc, unless there is one already. It
// always returns 0: when the creation fails, the last system error is turned into an HRESULT (0x146401, twice, at
// 0x179FF0 and 0x179FF5) and not used.
long __stdcall Object_001E4130::func_00179FA0(void *attributes, int manual, int signalled, const char *name)
{
    if (!event) {
        if (name)
            this->name.assign(name);
        event = func_00145AC5(attributes, manual, signalled, name);
        if (!event) {
            long error = (long)func_00146401() <= 0 ? (long)func_00146401() : (long)((func_00146401() & 0xFFFF) | 0x80070000);
        }
    }
    return 0;
}
