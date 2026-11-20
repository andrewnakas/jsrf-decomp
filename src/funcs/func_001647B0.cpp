struct Guid;

// The objects the class keeps in its list at +0x128.
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
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
    void clear()
    {
        func_0016E2C0(begin(), end_());
    }
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// The class whose table is at 0x1E19E0 (0x144 bytes).
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
    virtual long __stdcall func_001647B0(void *argument);

    void *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    char items[0x10];
    Object_00174220 list;
};

// Slot 10: lets go of the object (its slot 2) and empties its entry of the list at +0x128; 0x800710D8 when it is not
// there. A null object lets go of every entry and empties the list.
long __stdcall Object_001E19E0::func_001647B0(void *argument)
{
    Held *object = (Held *)argument;
    if (object) {
        long result = 0x800710D8;
        for (Object_00174220::iterator it = list.begin(), last = list.end_(); it != last; ++it) {
            if (*it == object) {
                if (*it) {
                    (*it)->slot2();
                    *it = 0;
                }
                result = 0;
                break;
            }
        }
        return result;
    }
    for (Object_00174220::iterator it = list.begin(); it != list.end_(); ++it) {
        if (*it) {
            (*it)->slot2();
            *it = 0;
        }
    }
    list.clear();
    return 0;
}
