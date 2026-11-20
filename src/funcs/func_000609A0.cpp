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

struct Vector3 {
    float x;
    float y;
    float z;
};


// The global flag 0x251DD4: whether the last lookup by func_000609A0 found nothing.
extern int data_00251DD4;

struct Entry_000607B0 : Node {
    char unknown_044[0x12c];
    int key;
    int parent;
    char unknown_178[0x104];
    Vector3 unknown_27c;
    Vector3 unknown_288;
};

struct Object_000607B0 {
    char unknown_00[0x28];
    Entry_000607B0 *entries;

    int func_000609A0(int key);
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

// Gives 1 (and sets 0x251DD4) when no entry is registered under the key, else 0 (and clears it).
int Object_000607B0::func_000609A0(int key)
{
    int result;
    if (find_000607B0(entries, key)) {
        result = 0;
    } else {
        result = 1;
    }
    data_00251DD4 = result;
    return result;
}
