// A list of 4-byte values (nodes of 0xc bytes): the one at +0x4c8 of the class whose table is at 0x1E3B90.
struct PointerList {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    Node *func_0016E330(Node *next, Node *previous, void *const &value);
    void func_0016E990(unsigned int count);
    void func_0016EEB0(void *const &value);

    char allocator;
    Node *head;
    unsigned int size;
};

// Appends a value (slot 0x16F4B0 of that class calls it): makes a node (0x16E330) linked before the head node, counts it (0x16E990, which throws
// std::length_error past the largest size) and links it in.
void PointerList::func_0016EEB0(void *const &value)
{
    Node *where = head;
    Node *node = func_0016E330(where, where->previous, value);
    func_0016E990(1);
    where->previous = node;
    node->previous->next = node;
}
