struct Guid;
struct Unknown;

// The objects the class keeps in its vector at +0x118.
struct Registered;

// The objects the class keeps in its list at +0x128 (slot 8 is told about each object of the vector, then 0).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall slot8(Registered *object);
};

// A std::vector of pointers.
struct RegisteredList {
    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// A list whose nodes are 0xc bytes: the next and previous links and a 4-byte value.
struct Object_00174220 {
    struct Node {
        Node *next;
        Node *previous;
        Held *value;
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
        Held *&operator*() const
        {
            return node->value;
        }
        iterator &operator++()
        {
            node = node->next;
            return *this;
        }
        bool operator!=(const iterator &other) const
        {
            return node != other.node;
        }
    };

    iterator begin()
    {
        return iterator(head == 0 ? 0 : head->next);
    }
    iterator end_()
    {
        return iterator(head);
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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_001642D0();

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    RegisteredList items;
    Object_00174220 list;
};

// Slot 11: tells each object of the list at +0x128 (its slot 8) about every object of the vector at +0x118, then
// about none. 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_001642D0()
{
    if (unknown_0c) {
        for (Object_00174220::iterator it = list.begin(); it != list.end_(); ++it) {
            Held *held = *it;
            if (held) {
                for (Registered **entry = items.first; entry != items.last; ++entry) {
                    if (*entry)
                        held->slot8(*entry);
                }
                held->slot8(0);
            }
        }
        return 0;
    }
    return 0x800401F0;
}
