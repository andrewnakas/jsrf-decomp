/* sym: ??1Object_001E3B00@@UAE@XZ = 0x0016B180 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;
struct Description;
struct Target;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The DirectSound object at +0xc and its release (0x19E4DC).
struct Sound;
unsigned long __stdcall func_0019E4DC(Sound *sound);

// The objects in the voice's lists.
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers.
struct BufferList {
    BufferList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~BufferList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Destroys the lists from `first` up to `last` (each frees its block).
void func_0016AC50(BufferList *first, BufferList *last, Allocator &allocator, Tag) throw();

// A std::vector of those lists.
struct GroupList {
    GroupList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~GroupList()
    {
        if (first) {
            func_0016AC50(first, last, allocator, Tag());
            operator delete(first);
        }
        first = 0;
        last = 0;
        end = 0;
    }

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// The number of live objects of the library's sound classes.
extern long data_00265198;

// The class whose table is at 0x1E3B00: the voices MGameSound8 makes (0x30 bytes).
struct Object_001E3B00 {
    Object_001E3B00(Unknown *outer);
    virtual long __stdcall func_00169D50(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00169550();
    virtual long __stdcall func_00169DE0(Sound *sound, const Description *description);
    virtual long __stdcall func_00169F50();
    virtual long __stdcall func_001695A0(void *argument);
    virtual long __stdcall func_0016AE50(unsigned int index, Buffer *buffer);
    virtual long __stdcall func_00169E90(void *argument1, void *argument2);
    virtual long __stdcall func_0016A5C0(void *argument);
    virtual long __stdcall func_00169580(Target *target, void *argument);
    virtual long __stdcall func_0016B6D0(unsigned int index, Buffer *buffer);
    virtual long __stdcall func_0016B240(void *argument);
    virtual long __stdcall func_00169960(unsigned int index, void *argument);
    virtual long __stdcall func_00169FA0(unsigned int index, void *argument);
    virtual long __stdcall func_001699B0(unsigned int index, void *argument);
    virtual long __stdcall func_0016A030(unsigned int index, void *argument);
    virtual long __stdcall func_0016A0C0(unsigned int index, void *argument);
    virtual long __stdcall func_0016A150(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_0016A1F0(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_0016A290(unsigned int index);
    virtual long __stdcall func_0016A310(unsigned int index);
    virtual long __stdcall func_0016A390(unsigned int index, void *argument);
    virtual long __stdcall func_00169A60(unsigned int index, void *argument);
    virtual long __stdcall func_0016A420(unsigned int index, void *argument);
    virtual long __stdcall func_0016A4B0(unsigned int index, void *argument);
    virtual long __stdcall func_00169A00(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00169EF0(void *argument1, void *argument2);
    virtual long __stdcall func_00169AB0(unsigned int index, void *argument);
    virtual long __stdcall func_00169B00(unsigned int index, void *argument1, void *argument2);
    virtual long __stdcall func_00169B60(unsigned int index, void *argument);
    virtual long __stdcall func_00169BB0(unsigned int index, void *argument);
    virtual long __stdcall func_00169C00(unsigned int index, void *argument);
    virtual long __stdcall func_00169C50(unsigned int index, void *argument);
    virtual long __stdcall func_00169CA0(unsigned int index, void *argument);
    virtual long __stdcall func_00169CF0(unsigned int index, void *argument1, void *argument2);
    virtual ~Object_001E3B00();

    Unknown *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Destructor: lets go of every buffer (slot 8 with none given), releases the DirectSound object (0x19E4DC) and the
// controlling object and counts the object out; the lists free their blocks.
Object_001E3B00::~Object_001E3B00()
{
    func_0016A5C0(0);
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
