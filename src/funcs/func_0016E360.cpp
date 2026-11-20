void *__cdecl operator new(unsigned int size);

// A list whose nodes are 0x10 bytes: the next and previous links and an 8-byte value (head node 0x16E310). The
// classes whose tables are at 0x1E3B90 and 0x1E3C08 keep one.
struct Object_0016E310 {
    // The 8-byte value of a node.
    struct Value {
        int first;
        int second;
    };

    struct Node {
        Node *next;
        Node *previous;
        Value value;
    };

    Node *func_0016E360(Node *next, Node *previous, const Value &value);

    char allocator;
    Node *head;
    unsigned int size;
};

// Makes a node linked to the given neighbours and holding a copy of the value (0x16F760, 0x16FBF0, 0x172540 and
// 0x1726F0 call it).
Object_0016E310::Node *Object_0016E310::func_0016E360(Node *next, Node *previous, const Value &value)
{
    Node *node = (Node *)operator new(sizeof(Node));
    if (node) {
        node->next = next;
        node->previous = previous;
        node->value = value;
    }
    return node;
}
