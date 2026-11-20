// A list of 4-byte values (nodes of 0xc bytes).
struct PointerList {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    Node *func_0016E330(Node *next, Node *previous, void *const &value);

    char allocator;
    Node *head;
    unsigned int size;
};

// Makes a node linked to the given neighbours and holding a copy of the value. The linker folded the node builders
// of several lists of 4-byte values into this one (0x165090, 0x16EEB0, 0x174510, 0x174550 and 0x174760 call it).
PointerList::Node *PointerList::func_0016E330(Node *next, Node *previous, void *const &value)
{
    Node *node = (Node *)operator new(sizeof(Node));
    if (node) {
        node->next = next;
        node->previous = previous;
        node->value = value;
    }
    return node;
}
