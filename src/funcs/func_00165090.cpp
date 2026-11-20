struct Guid;
struct Unknown;

// The objects the class keeps (slot 1 adds a reference).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A list of 4-byte values (nodes of 0xc bytes): the one at +0x128.
struct PointerList {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    Node *func_0016E330(Node *next, Node *previous, void *const &value);
    void func_00164AD0(unsigned int count);

    // Appends a value: a node (0x16E330) linked before the head node, counted by 0x164AD0.
    void push_back(void *const &value)
    {
        Node *where = head;
        Node *node = func_0016E330(where, where->previous, value);
        func_00164AD0(1);
        where->previous = node;
        node->previous->next = node;
    }

    char allocator;
    Node *head;
    unsigned int size;
};

// The class whose table is at 0x1E19E0.
struct Object_001E19E0 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_00165090(void *argument);

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    char items[0x10];
    PointerList list;
};

// Slot 8: adds a reference to the object and appends it to the list at +0x128. 0x80070057 (E_INVALIDARG) without an
// object, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_00165090(void *argument)
{
    if (unknown_0c) {
        if (argument) {
            ((Held *)argument)->slot1();
            list.push_back(argument);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
