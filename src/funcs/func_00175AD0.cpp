inline void *operator new(unsigned int, void *where)
{
    return where;
}

// A list whose nodes are 0x20 bytes: the next and previous links and a 0x18-byte value. The constructors 0x175BC0 and
// 0x177C40 build one.
struct Object_00175AD0 {
    struct Node {
        Node *next;
        Node *previous;
        int value[6];
    };

    char allocator;
    Node *head;
    unsigned int size;

    Node *func_00175AD0();
};

// Makes the head node: a node linked to itself both ways.
Object_00175AD0::Node *Object_00175AD0::func_00175AD0()
{
    Node *node = (Node *)operator new(sizeof(Node));
    new (&node->next) Node *(node);
    new (&node->previous) Node *(node);
    return node;
}
