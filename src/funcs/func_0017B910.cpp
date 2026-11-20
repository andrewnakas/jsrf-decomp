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

// The system library's thread function (kernel import #224), wait (0x145C7A) and close.
unsigned long __stdcall func_00147DD2(void *thread);
unsigned long __stdcall func_00145C7A(void *handle, unsigned long timeout);
int __stdcall func_00145585(void *handle);

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

// Destructor: with a thread, has the first object in the list stop (its slot 6 with 0), runs the thread, waits for
// it to end and closes it; lets go of every object in the list and frees it, lets go of the object at +0x3c and of
// the controlling object and counts the object out.
Object_001E420C::~Object_001E420C()
{
    if (thread) {
        (*list.first)->slot6(0);
        func_00147DD2(thread);
        func_00145C7A(thread, 0xFFFFFFFF);
        func_00145585(thread);
    }
    for (Listener **entry = list.first; entry != list.last; ++entry) {
        if (*entry) {
            (*entry)->slot2();
            *entry = 0;
        }
    }
    list.tidy();
    if (worker) {
        worker->slot2();
        worker = 0;
    }
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_002651D4);
}
