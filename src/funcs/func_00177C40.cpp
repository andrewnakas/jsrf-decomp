/* sym: ??0Object_001E3FE4@@QAE@PAUUnknown@@@Z = 0x00177C40 */
/* sym: ??1Object_001E3FE4@@UAE@XZ = 0x00177B80 */
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
        clear();
        operator delete(head);
        head = 0;
        size = 0;
    }

    // Erases every node.
    void clear()
    {
        func_0016E2C0(iterator(head == 0 ? 0 : head->next), iterator(head));
    }

    Node *func_00175AD0();
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// The number of live MFile2 objects.
extern long data_002651BC;

// The class whose table is at 0x1E3FE4: one of the classes the MFile2 factory (0x1E3F1C) creates (0x34 bytes). Slots
// 5 to 9 pass the call on to the object at +0xc; the tables 0x1E3D30, 0x1E3D88 and 0x1E3FB0 hold some of the same
// functions, and its Release is the one of 0x1E420C (the linker folded the identical functions).
struct Object_001E3FE4 {
    Object_001E3FE4(Unknown *outer);
    virtual long __stdcall func_00177600(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0017B6A0();
    virtual long __stdcall func_001772C0(void *argument);
    virtual long __stdcall func_00177870(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_001773A0(void *argument1, void *argument2);
    virtual long __stdcall func_001773C0(void *argument);
    virtual long __stdcall func_001773E0(void *argument);
    virtual long __stdcall func_00177400(void *argument1, void *argument2);
    virtual long __stdcall func_001775E0(void *argument);
    virtual long __stdcall func_00177420(void *argument);
    virtual long __stdcall func_001774F0(void *argument);
    virtual long __stdcall func_00177DB0(void *argument);
    virtual long __stdcall func_00177E40(void *argument);
    virtual ~Object_001E3FE4();

    Unknown *outer;
    long references;
    Unknown *inner;
    void *file;
    unsigned long unknown_14;
    unsigned long unknown_18;
    unsigned long unknown_1c;
    unsigned long unknown_20;
    bool unknown_24;
    Object_00175AD0 list;
};

// Constructor: one reference, no inner object, no file (-1), the words at +0x14 and the flag at +0x24 zero, the list
// empty; holds a reference to the controlling object, if any, and counts the object in.
Object_001E3FE4::Object_001E3FE4(Unknown *outer)
    : outer(outer), references(1), inner(0), file((void *)-1), unknown_14(0), unknown_18(0), unknown_1c(0),
      unknown_20(0), unknown_24(false)
{
    if (this->outer)
        this->outer->slot1();
    _InterlockedIncrement(&data_002651BC);
}
