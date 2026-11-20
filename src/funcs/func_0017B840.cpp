struct Guid;
struct Unknown;

// The objects in the list at +0x40 of the MThread class (slot 1 adds a reference).
struct Client {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A std::vector of pointers.
struct ClientList {
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    char allocator;
    Client **first;
    Client **last;
    Client **end;
};

// The MThread class (table 0x1E41D8). The table at 0x1E420C holds the same function in slot 5.
struct Object_001E41D8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_0017B840(void *argument1, void *argument2);

    Unknown *outer;
    long references;
    void *thread;
    unsigned long unknown_10;
    int value;
    unsigned long unknown_18;
    unsigned long unknown_1c;
    unsigned long section[7];
    Unknown *worker;
    ClientList list;
};

// Slot 5: gives out the object at `index` + 2 of the list at +0x40 with a reference added; 1 (and a null object) when
// that place is empty, 0x80070057 (E_INVALIDARG, and a null object) past the end or without a place for it.
// 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E41D8::func_0017B840(void *argument1, void *argument2)
{
    if (thread) {
        argument1 = (char *)argument1 + 2;
        Client **object = (Client **)argument2;
        if (object) {
            if ((unsigned int)argument1 < list.size()) {
                Client *client = list.first[(unsigned int)argument1];
                if (client) {
                    client->slot1();
                    *object = client;
                    return 0;
                }
                *object = 0;
                return 1;
            }
            *object = 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
