struct Guid;

// The 0x14-byte description slot 6 gives out: a size at +4 among other words.
struct Info {
    unsigned long unknown_00;
    unsigned long size;
    unsigned long unknown_08[3];
};

// The objects in the list at +0x2c (slot 6 describes one).
struct Held {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(Info *info);
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

// The class whose table is at 0x1E3DE4 (0x38 bytes).
struct Object_001E3DE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00173FC0(void *argument);

    void *outer;
    long references;
    void *ready;
    void *source;
    long position;
    Info info;
    Object_00174220 list;
};

// Slot 6: gives out the 0x14-byte description at +0x18. Its size is worked out first while it is 0: each object of
// the list adds its own size plus an 8-byte header, rounded up to an even count, and a non-empty list adds 4.
// E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3DE4::func_00173FC0(void *argument)
{
    if (ready) {
        if (!info.size) {
            for (Object_00174220::iterator it = list.begin(); it != list.end_(); ++it) {
                Info child;
                if ((*it)->slot6(&child) >= 0) {
                    if (child.size & 1)
                        info.size++;
                    info.size += child.size + 8;
                }
            }
            if (list.size)
                info.size += 4;
        }
        if (argument) {
            *(Info *)argument = info;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
