struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

struct Entry_000607B0 : Node {
    char unknown_044[0x12c];
    int key;
    int parent;
    char unknown_178[0x1354];
    int unknown_14cc;
};

struct Object_000607B0 {
    char unknown_00[0x28];
    Entry_000607B0 *entries;

    void func_000607B0(int key);
    void func_00060810(int key);
};

// The entry registered under a key, or 0.
inline Entry_000607B0 *find_000607B0(Entry_000607B0 *entries, int key)
{
    for (Entry_000607B0 *entry = entries; entry; entry = (Entry_000607B0 *)entry->next) {
        if (entry->key == key) {
            return entry;
        }
    }
    return 0;
}

// Clears +0x14cc of the entry registered under a key and of each of its parents.
void Object_000607B0::func_000607B0(int key)
{
    Entry_000607B0 *entry = find_000607B0(entries, key);
    if (entry) {
        entry->unknown_14cc = 0;
        if (entry->parent && find_000607B0(entries, entry->parent)) {
            func_000607B0(entry->parent);
        }
    }
}
