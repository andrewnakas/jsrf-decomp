struct Guid;

// The objects in the list at +0x128; +0x34 is the key slots 12 and 13 look for.
struct Item {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall slot4(void *argument);
    char unknown_04[0x30];
    int key;
};

// A node of the list (a std::list: a ring through the head node).
struct Node {
    Node *next;
    Node *previous;
    Item *item;
};

// The list at +0x128.
struct ItemList {
    char allocator;
    Node *head;
    unsigned int size;

    Node *begin() const
    {
        return head == 0 ? 0 : head->next;
    }
};

// The class whose table is at 0x1E19E0: the objects MGameInput8's slot 8 makes (0x144 bytes).
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
    virtual long __stdcall func_001644C0(int key, void *argument);

    char unknown_04[8];
    void *ready;
    char unknown_10[0x118];
    ItemList items;
};

// Slot 12: passes the argument on to slot 4 of every object of the list at +0x128 whose key (+0x34) is `key`.
// E_INVALIDARG for a null argument, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E19E0::func_001644C0(int key, void *argument)
{
    if (ready) {
        if (argument) {
            for (Node *node = items.begin(); node != items.head; node = node->next) {
                Item *item = node->item;
                if (item && item->key == key)
                    item->slot4(argument);
            }
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
