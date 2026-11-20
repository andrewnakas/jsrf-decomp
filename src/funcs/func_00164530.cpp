struct Guid;

// The objects the class keeps in its list at +0x128 (each with a key at +0x34).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall slot5(void *argument);

    char unknown_04[0x30];
    int key;
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
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall func_00164530(int key, void *argument);

    void *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    char items[0x10];
    Object_00174220 list;
};

// Slot 13: passes the argument to slot 5 of the first object of the list at +0x128 with the key (+0x34); 0x800710D8
// when there is none. E_INVALIDARG for a null argument, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_00164530(int key, void *argument)
{
    long result;
    if (unknown_0c) {
        if (argument) {
            result = 0x800710D8;
            for (Object_00174220::iterator it = list.begin(), last = list.end_(); it != last; ++it) {
                Held *held = *it;
                if (held && held->key == key) {
                    result = held->slot5(argument);
                    break;
                }
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
