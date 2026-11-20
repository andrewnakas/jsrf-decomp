/* sym: ??1Object_001E19E0@@UAE@XZ = 0x001649C0 */
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

struct Item;
struct Other;

// The std::vector of pointers at +0x118.
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

// The std::vector of pointers at +0x134.
struct OtherVector {
    OtherVector()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~OtherVector()
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
    Other **first;
    Other **last;
    Other **end;
};

// The number of live objects of the library's input classes.
extern long data_0026517C;

// The class whose table is at 0x1E19E0 (0x144 bytes).
struct Object_001E19E0 {
    Object_001E19E0(Unknown *outer);
    virtual long __stdcall func_00163DB0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00163B90();
    virtual long __stdcall func_00165130(void *argument1, void *argument2);
    virtual long __stdcall func_001652E0(void *argument);
    virtual long __stdcall func_00164080(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00164900(void *argument);
    virtual long __stdcall func_00163BC0(void *argument1, void *argument2);
    virtual long __stdcall func_00165090(void *argument);
    virtual long __stdcall func_001641E0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001647B0(void *argument);
    virtual long __stdcall func_001642D0();
    virtual long __stdcall func_001644C0(int key, void *argument);
    virtual long __stdcall func_00164530(int key, void *argument);
    virtual long __stdcall func_001645B0(void *argument);
    virtual long __stdcall func_00163CD0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001646C0(void *argument1, void *argument2, void *argument3);
    virtual ~Object_001E19E0();

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    ItemVector items;
    Object_00174220 list;
    OtherVector others;
};

// Destructor: runs slots 10 and 6 with a null argument, frees the vector at +0x134, lets go of the controlling
// object and counts the object out; the vectors and the list free their blocks.
Object_001E19E0::~Object_001E19E0()
{
    func_001647B0(0);
    func_00164900(0);
    others.tidy();
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_0026517C);
}
