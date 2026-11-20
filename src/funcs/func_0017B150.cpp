/* sym: ??0Object_001E41D8@@QAE@PAUUnknown@@@Z = 0x0017B150 */
/* sym: ??1Object_001E41D8@@UAE@XZ = 0x0017AC20 */
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

struct Info;

// The objects in the list at +0x40.
struct Client {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6();
};

// A std::vector of pointers.
struct ClientList {
    ClientList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~ClientList()
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
    Client **first;
    Client **last;
    Client **end;
};

// Kernel import #291 (the import table's slot at 0x1C4094), which the constructor runs on the block at +0x20.
extern void(__stdcall *data_001C4094)(void *block);

// The number of live MThread objects.
extern long data_002651D4;

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown and the
// interface 0x1E41B8 (0x50 bytes). Its Release is the one of 0x1E202C and slots 5, 8, 9 and 11 hold the same
// functions as the table at 0x1E420C (the linker folded the identical functions).
struct Object_001E41D8 {
    Object_001E41D8(Unknown *outer);
    virtual long __stdcall func_0017AAA0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00165E90();
    virtual long __stdcall func_0017B3E0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_0017B580(Client *entry);
    virtual long __stdcall func_0017B840(void *argument1, void *argument2);
    virtual long __stdcall func_0017B5D0(void *argument);
    virtual long __stdcall func_0017AB70(const Info *info);
    virtual long __stdcall func_0017B6D0(Info *info);
    virtual long __stdcall func_0017A9B0(void *argument);
    virtual long __stdcall func_0017AA50();
    virtual long __stdcall func_0017AA80();
    virtual ~Object_001E41D8();

    Unknown *outer;
    long references;
    void *thread;
    unsigned long unknown_10;
    int value;
    unsigned long unknown_18;
    unsigned long unknown_1c;
    unsigned long section[7];
    Unknown *worker;
    ClientList list;
};

// Constructor: one reference, no thread, the words at +0x10, the object at +0x3c and the list empty; it keeps no
// controlling object (+4 is set to null whatever it is given, so the AddRef below never runs); sets up the block at
// +0x20 (kernel import #291) and counts the object in.
Object_001E41D8::Object_001E41D8(Unknown *outer)
    : outer(0), references(1), thread(0), unknown_10(0), value(0), unknown_18(0), unknown_1c(0), worker(0)
{
    if (this->outer)
        this->outer->slot1();
    data_001C4094(section);
    _InterlockedIncrement(&data_002651D4);
}
