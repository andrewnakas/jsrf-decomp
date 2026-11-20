void operator delete(void *memory);

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xeb (constructor func_000BB1A0, destructor func_000BAC20).
struct Object_000BAC20 {
    void func_000BAD80(int id);
};

// An entry of the list at +0x240: an object's id, linked through +0x8.
struct Entry_0004C350 {
    int id;
    int unknown_04;
    Entry_0004C350 *next;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_000[0x240];
    Entry_0004C350 *entries;
    Entry_0004C350 **tail;

    void func_0004C350();
};

// Called at the end of func_0004CEB0: for each entry of the list at +0x240, runs func_000BAD80 of object 0xeb (when it
// exists) with the entry's id, takes that object out with everything below it and frees the entry; then empties the
// list.
void Object_0004ABA0::func_0004C350()
{
    Object_000BAC20 *owner = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
    Entry_0004C350 *entry = entries;
    while (entry) {
        Entry_0004C350 *next = entry->next;
        if (owner)
            owner->func_000BAD80(entry->id);
        Node *node = (Node *)data_0022FCE0->func_000128C0(entry->id);
        if (node) {
            node->func_00011BE0(node);
            node->func_00011C20(node->child);
        }
        operator delete(entry);
        entry = next;
    }
    entries = 0;
    tail = &entries;
}
