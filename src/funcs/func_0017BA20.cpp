/* sym: ??0Object_001E420C@@QAE@PAUUnknown@@@Z = 0x0017BA20 */
/* sym: ??1Object_001E420C@@UAE@XZ = 0x0017B910 */
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
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(int all);
};

// A std::vector of pointers.
struct ListenerList {
    ListenerList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~ListenerList()
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
    Listener **first;
    Listener **last;
    Listener **end;
};

// Kernel import #291 (the import table's slot at 0x1C4094), which the constructor runs on the block at +0x20.
extern void(__stdcall *data_001C4094)(void *block);

// The number of live MThread objects.
extern long data_002651D4;

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8
// (0x50 bytes). Its Release is the one of 0x1E3FE4 and slots 5, 8, 9 and 11 hold the same functions as the table at
// 0x1E41D8 (the linker folded the identical functions).
struct Object_001E420C {
    Object_001E420C(Unknown *outer);
    virtual long __stdcall func_0017B7D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0017B6A0();
    virtual long __stdcall func_0017BC70(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_0017BE20(Listener *listener);
    virtual long __stdcall func_0017B840(void *argument1, void *argument2);
    virtual long __stdcall func_0017BE70(void *argument);
    virtual long __stdcall func_0017B8C0(const Info *info);
    virtual long __stdcall func_0017B6D0(Info *info);
    virtual long __stdcall func_0017A9B0(void *argument);
    virtual long __stdcall func_0017B710();
    virtual long __stdcall func_0017AA80();
    virtual long __stdcall func_0017B740(int argument);
    virtual long __stdcall func_0017B770(unsigned int argument1, int argument2, int argument3);
    virtual ~Object_001E420C();

    Unknown *outer;
    long references;
    void *thread;
    unsigned long unknown_10;
    int value;
    unsigned long unknown_18;
    unsigned long unknown_1c;
    unsigned long section[7];
    Unknown *worker;
    ListenerList list;
};

// Constructor: one reference, no thread, the words at +0x10, the object at +0x3c and the list empty; holds a
// reference to the controlling object, if any, sets up the block at +0x20 (kernel import #291) and counts the
// object in.
Object_001E420C::Object_001E420C(Unknown *outer)
    : outer(outer), references(1), thread(0), unknown_10(0), value(0), unknown_18(0), unknown_1c(0), worker(0)
{
    if (this->outer)
        this->outer->slot1();
    data_001C4094(section);
    _InterlockedIncrement(&data_002651D4);
}
