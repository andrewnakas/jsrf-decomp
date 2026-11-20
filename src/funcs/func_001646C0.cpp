struct Guid;
struct Unknown;

// The objects the class keeps in its vector at +0x118.
struct Registered;

// One 0x5c-byte entry of the array slot 16 fills.
struct Entry {
    char unknown[0x5c];
};

// The objects the class keeps in its list at +0x128 (slot 7 fills an entry).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(Entry *entry);
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
    iterator end()
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual long __stdcall func_001646C0(void *argument1, void *argument2, void *argument3);

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    RegisteredList items;
    Object_00174220 list;
};

// Slot 16: has each object of the list at +0x128 fill the next of the `count` entries (its slot 7) until one fails or
// the entries run out, and gives out how many were filled; returns the last slot 7 result (the count itself when
// the list holds no object). 0x80070057 (E_INVALIDARG) without a count or entries,
// 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_001646C0(void *argument1, void *argument2, void *argument3)
{
    long result;
    if (unknown_0c) {
        if (argument1 && argument2) {
            unsigned int count = (unsigned int)argument1;
            unsigned int filled = 0;
            Object_00174220::iterator it = list.begin();
            Entry *entry = (Entry *)argument2;
            for (; it != list.end(); ++it) {
                Held *held = *it;
                if (held) {
                    result = held->slot7(entry);
                    if (result < 0)
                        break;
                    ++filled;
                    ++entry;
                    if (filled >= count)
                        break;
                }
            }
            if (argument3)
                *(unsigned int *)argument3 = filled;
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
