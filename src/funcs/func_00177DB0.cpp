struct Guid;
struct Unknown;

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
    void func_00177D00(unsigned int count);

    // Appends a copy of the value: a node (0x177B50) linked before the head node, counted by 0x177D00.
    void push_back(const Value &value)
    {
        Node *where = head;
        Node *node = func_00177B50(where, where->previous, value);
        func_00177D00(1);
        where->previous = node;
        node->previous->next = node;
    }

    char allocator;
    Node *head;
    unsigned int size;
};

// The object at +0xc: slot 7 fills in a 64-bit value (two words).
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(int *value);
};

// The class whose table is at 0x1E3FE4.
struct Object_001E3FE4 {
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
    virtual long __stdcall func_00177DB0(void *argument);

    Unknown *outer;
    long references;
    Inner *inner;
    void *file;
    unsigned long unknown_14;
    unsigned long unknown_18;
    unsigned long unknown_1c;
    unsigned long unknown_20;
    bool unknown_24;
    Object_00175AD0 list;
};

// Slot 12: appends a copy of the 0x18-byte record to the list at +0x28; when the record's 64-bit value at +8 is zero,
// has slot 7 of the object at +0xc fill it in first. 0x80070057 (E_INVALIDARG) without a record, 0x800401F0 (not
// initialised) while +0xc is null.
long __stdcall Object_001E3FE4::func_00177DB0(void *argument)
{
    if (inner) {
        if (argument) {
            Object_00175AD0::Value record = *(const Object_00175AD0::Value *)argument;
            if ((record.word[3] | record.word[2]) == 0)
                inner->slot7(&record.word[2]);
            list.push_back(record);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
