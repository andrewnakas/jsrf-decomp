/* sym: ??1Object_001E3DE4@@UAE@XZ = 0x001743B0 */
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

struct Source;

// A list whose nodes are 0xc bytes: the next and previous links and a 4-byte value.
struct Object_00174220 {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
    };

    Object_00174220()
    {
        head = func_00174220();
        size = 0;
    }
    ~Object_00174220()
    {
        func_0016E2C0(iterator(head == 0 ? 0 : head->next), iterator(head));
        operator delete(head);
        head = 0;
        size = 0;
    }

    Node *func_00174220();
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// The number of live objects of the library's RIFF file classes.
extern long data_002651A4;

// The class whose table is at 0x1E3DE4 (0x38 bytes).
struct Object_001E3DE4 {
    Object_001E3DE4(Unknown *outer);
    virtual long __stdcall func_00173F30(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00173B80();
    virtual long __stdcall func_001746E0(void *argument1, void *argument2);
    virtual long __stdcall func_00174060(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00174120(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00173FC0(void *argument);
    virtual long __stdcall func_00173ED0(Source **source);
    virtual long __stdcall func_00173CF0(void *argument1, void *argument2);
    virtual long __stdcall func_00173D70(long *position);
    virtual long __stdcall func_00173DB0(void *argument1, void *argument2, void *argument3, void *argument4);
    virtual long __stdcall func_00174760(void *argument1, void *argument2);
    virtual long __stdcall func_00174240(void *argument);
    virtual ~Object_001E3DE4();

    Unknown *outer;
    long references;
    void *ready;
    Source *source;
    long position;
    unsigned long unknown_18[5];
    Object_00174220 list;
};

// Destructor: runs slot 12 with a null argument, lets go of the controlling object and counts the object out; the
// list frees its nodes.
Object_001E3DE4::~Object_001E3DE4()
{
    func_00174240(0);
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_002651A4);
}
