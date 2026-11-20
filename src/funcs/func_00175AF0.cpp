/* sym: ??1MemStream@@UAE@XZ = 0x00175AF0 */
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

// The system library's process heap and heap free.
void *__stdcall func_0014A838();
int __stdcall func_0014A821(void *heap, unsigned long flags, void *memory);

// A list whose nodes are 0x20 bytes: the next and previous links and a 0x18-byte value. Its erase (0x16E2C0) and
// destructor (0x177B10) are the same functions as those of the list with 0xc-byte nodes (head node 0x174220).
struct Object_00175AD0 {
    struct Node {
        Node *next;
        Node *previous;
        int value[6];
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
    };

    Object_00175AD0()
    {
        head = func_00175AD0();
        size = 0;
    }
    ~Object_00175AD0()
    {
        func_0016E2C0(iterator(head == 0 ? 0 : head->next), iterator(head));
        operator delete(head);
        head = 0;
        size = 0;
    }

    Node *func_00175AD0();
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// The number of live MemStream objects.
extern long data_002651B0;

// MemStream's first interface: the table at 0x1E3EA8.
struct __declspec(novtable) FirstInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct __declspec(novtable) SecondInterface {
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual long __stdcall func_00174C70(void **data, unsigned long *length);
};

// MemStream, a stream over a block of memory (0x78 bytes, two interfaces, like MGameSound8). Its AddRef and the
// second interface's AddRef thunk are MGameSound8's (the linker folded the identical functions); the other thunks
// are 0x175BB0 (QueryInterface) and 0x175BA0 (Release).
struct MemStream : FirstInterface, SecondInterface {
    MemStream(Unknown *outer);
    virtual long __stdcall func_001753D0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00174C20();
    virtual unsigned long __stdcall func_00174C40();
    virtual long __stdcall func_00174CB0(void *argument, unsigned long size);
    virtual long __stdcall func_00175900(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00174D70(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00174F60(void *argument1, void *argument2);
    virtual long __stdcall func_00174FE0(__int64 *position);
    virtual long __stdcall func_00175030(unsigned __int64 *capacity);
    virtual long __stdcall func_00175070(void *argument);
    virtual long __stdcall func_00175170(const unsigned __int64 &capacity);
    virtual long __stdcall func_001751B0();
    virtual long __stdcall func_00175250(void *argument);
    virtual long __stdcall func_00175300(void *argument);
    virtual long __stdcall func_00175D60(void *argument);
    virtual long __stdcall func_00175DC0(void *argument);
    virtual long __stdcall func_00175F60(void *argument);
    virtual long __stdcall func_00174C70(void **data, unsigned long *length);
    virtual ~MemStream();

    Unknown *outer;
    long references;
    void *data;
    unsigned long unknown_14;
    __int64 length;
    unsigned __int64 capacity;
    __int64 position;
    int growable;
    int mode;
    void *file;
    unsigned long unknown_3c;
    unsigned long unknown_40;
    unsigned long unknown_44;
    unsigned long unknown_48;
    unsigned long unknown_4c;
    unsigned long unknown_50;
    unsigned long unknown_54;
    unsigned long unknown_58;
    unsigned long unknown_5c;
    bool unknown_60;
    unsigned long unknown_64;
    Object_00175AD0 list;
    unsigned long unknown_74;
};

// Destructor: frees the block with the process heap when the stream owns it (mode bit 2), lets go of the
// controlling object and counts the object out; the list frees its nodes.
MemStream::~MemStream()
{
    if ((mode & 2) && data) {
        func_0014A821(func_0014A838(), 0, data);
        data = 0;
    }
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_002651B0);
}
