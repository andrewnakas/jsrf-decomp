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

// An entry of the list at +0x240: an object's id, a key, the next entry and the link that points at this one.
struct Entry_0004C350 {
    int id;
    int key;
    Entry_0004C350 *next;
    Entry_0004C350 **link;
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_000[0x240];
    Entry_0004C350 *entries;
    Entry_0004C350 **tail;

    void func_0004C2A0(int key);
};

// Called by func_000585E0: when object 0xeb exists, finds the entry of the list at +0x240 with `key`, runs
// func_000BAD80 of object 0xeb with its id, takes that object out with everything below it, unlinks the entry and
// frees it.
void Object_0004ABA0::func_0004C2A0(int key)
{
    Object_000BAC20 *owner = (Object_000BAC20 *)data_0022FCE0->func_000128C0(0xeb);
    if (!owner)
        return;
    for (Entry_0004C350 *entry = entries; entry; entry = entry->next) {
        if (entry->key == key) {
            owner->func_000BAD80(entry->id);
            Node *node = (Node *)data_0022FCE0->func_000128C0(entry->id);
            if (node) {
                node->func_00011BE0(node);
                node->func_00011C20(node->child);
            }
            *entry->link = entry->next;
            if (entry->next)
                entry->next->link = entry->link;
            else
                tail = entry->link;
            operator delete(entry);
            return;
        }
    }
}
