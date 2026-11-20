inline void *operator new(unsigned int, void *where)
{
    return where;
}

// A list whose nodes are 0x10 bytes: the next and previous links and a 8-byte value. The constructors 0x16F020 and
// 0x1722F0 build one (at +0x3d0 in the second).
struct Object_0016E310 {
    struct Node {
        Node *next;
        Node *previous;
        int value[2];
    };

    char allocator;
    Node *head;
    unsigned int size;

    Node *func_0016E310();
};

// Makes the head node: a node linked to itself both ways.
Object_0016E310::Node *Object_0016E310::func_0016E310()
{
    Node *node = (Node *)operator new(sizeof(Node));
    new (&node->next) Node *(node);
    new (&node->previous) Node *(node);
    return node;
}
