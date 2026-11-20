// A list whose nodes are 0xc bytes: the next and previous links and a 4-byte value.
struct Object_00174220 {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
    };

    Node *func_0016E330(Node *next, Node *previous, void *const &value);
    void func_00174460(unsigned int count);
    iterator func_00174510(iterator where, void *const &value);

    char allocator;
    Node *head;
    unsigned int size;
};

// Inserts a value before `where`: makes a node (0x16E330), counts it (0x174460, which throws std::length_error past
// the largest size), links it in and returns its iterator. Slot 11 of the class whose table is at 0x1E3DE4
// (0x174760) calls it.
Object_00174220::iterator Object_00174220::func_00174510(iterator where, void *const &value)
{
    Node *node = func_0016E330(where.node, where.node->previous, value);
    func_00174460(1);
    where.node->previous = node;
    node->previous->next = node;
    return iterator(where.node->previous);
}
