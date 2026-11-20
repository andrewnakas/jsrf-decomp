void *__cdecl operator new(unsigned int size);

// A list whose nodes are 0x20 bytes: the next and previous links and a 0x18-byte value (head node 0x175AD0). MemStream
// and the class whose table is at 0x1E3FE4 keep one.
struct Object_00175AD0 {
    // The 0x18-byte value of a node.
    struct Value {
        int word[6];
    };

    struct Node {
        Node *next;
        Node *previous;
        Value value;
    };

    Node *func_00177B50(Node *next, Node *previous, const Value &value);

    char allocator;
    Node *head;
    unsigned int size;
};

// Makes a node linked to the given neighbours and holding a copy of the value (0x175D60, 0x175DC0, 0x175F60, 0x177DB0
// and 0x177E40 call it).
Object_00175AD0::Node *Object_00175AD0::func_00177B50(Node *next, Node *previous, const Value &value)
{
    Node *node = (Node *)operator new(sizeof(Node));
    if (node) {
        node->next = next;
        node->previous = previous;
        node->value = value;
    }
    return node;
}
