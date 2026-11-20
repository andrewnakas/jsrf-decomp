/* sym: ??1MGameSound8@@UAE@XZ = 0x00168F60 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Voice;
struct Caps;

// The DirectSound object at +0x14 and its release (0x19E4DC).
struct Sound;
unsigned long __stdcall func_0019E4DC(Sound *sound);

// The list at +0x1c (a std::vector of pointers).
struct VoiceList {
    VoiceList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~VoiceList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Voice **first;
    Voice **last;
    Voice **end;
};

// The number of live objects of the library's sound classes.
extern long data_00265198;

// MGameSound8's first interface: the table at 0x1E3A70.
struct __declspec(novtable) FirstInterface {
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
};

// MGameSound8's second interface, at +4: the table at 0x1E3A5C.
struct __declspec(novtable) SecondInterface {
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
    virtual long __stdcall func_00168400(const Guid &id, void **object);
};

// MGameSound8, the class its factory (table 0x1E38E4, after the "MUSASHI.MGameSound8.1" strings) creates (0x2c
// bytes). The second interface's first three slots are the compiler's adjustor thunks 0x169010, 0x168FF0 and
// 0x169000.
struct MGameSound8 : FirstInterface, SecondInterface {
    MGameSound8(Unknown *outer);
    virtual long __stdcall func_00168310(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00168230();
    virtual long __stdcall func_00168480(void *argument);
    virtual long __stdcall func_00169460(unsigned int index, void *argument, Voice **voice);
    virtual long __stdcall func_00168AF0(unsigned int index, Voice **voice);
    virtual long __stdcall func_00168EC0(unsigned int index);
    virtual long __stdcall func_00168550();
    virtual long __stdcall func_00168500(Caps *caps);
    virtual long __stdcall func_001684E0(void *argument);
    virtual long __stdcall func_001504B0(void *argument);
    virtual long __stdcall func_001685B0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168610(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168670(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_001686D0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168730(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168790(unsigned int index, void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00168850(unsigned int index, void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001688B0(unsigned int index, void *argument);
    virtual long __stdcall func_00168910(unsigned int index, void *argument);
    virtual long __stdcall func_00168970(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_001689D0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168A30(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168A90(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_001687F0(unsigned int index, void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00168B60(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168BC0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168C20(unsigned int index, void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00168C80(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168CE0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168D40(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168DA0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168E00(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168E60(unsigned int index, void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00168260(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00168400(const Guid &id, void **object);
    virtual ~MGameSound8();

    Unknown *outer;
    long references;
    unsigned long unknown_10;
    Sound *sound;
    unsigned long unknown_18;
    VoiceList voices;
};

// Destructor: lets go of every voice (slot 6 with index -1), releases the DirectSound object (0x19E4DC) and the
// controlling object and counts the object out; the voice list frees its block.
MGameSound8::~MGameSound8()
{
    func_00168EC0(0xFFFFFFFF);
    if (sound) {
        func_0019E4DC(sound);
        sound = 0;
    }
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_00265198);
}
