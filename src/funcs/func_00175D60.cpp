struct Guid;

// A list whose nodes are 0x20 bytes: the next and previous links and a 0x18-byte value (head node 0x175AD0).
struct Object_00175AD0 {
    // The 0x18-byte value of a node.
    struct Value {
        int word[6];
    };

    struct Node {
        Node *next;
        Node *previous;
        Value value;
    };

    Node *func_00177B50(Node *next, Node *previous, const Value &value);
    void func_00175CB0(unsigned int count);

    // Appends a copy of the value: a node (0x177B50) linked before the head node, counted by 0x175CB0.
    void push_back(const Value &value)
    {
        Node *where = head;
        Node *node = func_00177B50(where, where->previous, value);
        func_00175CB0(1);
        where->previous = node;
        node->previous->next = node;
    }

    char allocator;
    Node *head;
    unsigned int size;
};

// MemStream's first interface: the table at 0x1E3EA8.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual long __stdcall func_00175D60(void *record);
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_00175D60(void *record);

    void *outer;
    long references;
    void *data;
    char unknown_14[4];
    __int64 length;
    unsigned __int64 capacity;
    __int64 position;
    int growable;
    int mode;
    void *file;
    char unknown_3c[0x2c];
    Object_00175AD0 list;
};

// Slot 14: appends a copy of the 0x18-byte record to the list at +0x68 (a node from 0x177B50, counted by 0x175CB0,
// linked before the head node). 0x80070057 (E_INVALIDARG) without a record, 0x800401F0 (not initialised) before
// slot 3.
long __stdcall MemStream::func_00175D60(void *record)
{
    if (mode) {
        if (record) {
            list.push_back(*(const Object_00175AD0::Value *)record);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
