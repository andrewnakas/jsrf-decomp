/* sym: ??1Object_001E1968@@UAE@XZ = 0x00163240 */
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

struct Entry;
struct Item;
struct Description;
struct Block;

// The std::vector of pointers at +0x3b4.
struct ItemVector {
    ItemVector()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~ItemVector()
    {
        tidy();
    }
    // Frees the block and leaves the vector empty.
    void tidy()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Item **first;
    Item **last;
    Item **end;
};

// The lists at +0x3c8 and +0x3d8: std::vectors of pointers.
struct EntryList {
    EntryList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~EntryList()
    {
        tidy();
    }
    // Frees the block and leaves the vector empty.
    void tidy()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Entry **first;
    Entry **last;
    Entry **end;
};

// The objects at +0x20 and +0x3b0.
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall slot8();
};

// The number of live objects of the library's input classes.
extern long data_0026517C;

// The class whose table is at 0x1E1968 (0x3e8 bytes).
struct Object_001E1968 {
    Object_001E1968(Unknown *outer);
    virtual long __stdcall func_00162A20(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00161C60();
    virtual long __stdcall func_001638D0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00163B00(Entry *entry);
    virtual long __stdcall func_00162D10(int index, Entry **entry);
    virtual long __stdcall func_001630C0(void *argument);
    virtual long __stdcall func_00162AB0(void *argument1, void *argument2);
    virtual long __stdcall func_00161FF0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00161D30(Description *description);
    virtual long __stdcall func_00162C60();
    virtual long __stdcall func_00161E70(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00161DC0();
    virtual long __stdcall func_001504B0(void *argument);
    virtual long __stdcall func_00162490(void *argument);
    virtual long __stdcall func_00162D80(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00163180(void *argument);
    virtual long __stdcall func_00163B40(Entry *entry);
    virtual long __stdcall func_001624B0(void *argument1, void *argument2);
    virtual long __stdcall func_00162460();
    virtual long __stdcall func_00162520(void *argument1, void *argument2);
    virtual long __stdcall func_00162580(void *argument1, void *argument2);
    virtual long __stdcall func_00162900(int index, void *argument1, void *argument2);
    virtual long __stdcall func_00162960(int *argument, Block *block);
    virtual long __stdcall func_00162990(Block *block);
    virtual long __stdcall func_001629C0(void *argument);
    virtual long __stdcall func_001629E0(void *argument);
    virtual long __stdcall func_00161F80(unsigned long *argument);
    virtual ~Object_001E1968();

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    void *context;
    char unknown_14[0xc];
    Inner *device;
    unsigned long block[0xa3];
    unsigned long unknown_2b0[0x40];
    Inner *inner;
    ItemVector items;
    void *other;
    EntryList first;
    EntryList second;
};

// Destructor: has the inner object stop (its slot 8), runs slot 16 with a null argument, frees the list at +0x3b4,
// lets go of the object at +0x20, of the inner object and of the controlling object and counts the object out; the
// lists free their blocks.
Object_001E1968::~Object_001E1968()
{
    if (inner)
        inner->slot8();
    func_00163180(0);
    items.tidy();
    if (device) {
        device->slot2();
        device = 0;
    }
    if (inner) {
        inner->slot2();
        inner = 0;
    }
    if (inner) {
        inner->slot2();
        inner = 0;
    }
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_0026517C);
}
