inline void *operator new(unsigned int, void *where)
{
    return where;
}

// A list whose nodes are 0xc bytes: the next and previous links and a 4-byte value. The constructors 0x164FD0,
// 0x16F020 and 0x174310 build one.
struct Object_00174220 {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    char allocator;
    Node *head;
    unsigned int size;

    Node *func_00174220();
};

// Makes the head node: a node linked to itself both ways.
Object_00174220::Node *Object_00174220::func_00174220()
{
    Node *node = (Node *)operator new(sizeof(Node));
    new (&node->next) Node *(node);
    new (&node->previous) Node *(node);
    return node;
}
