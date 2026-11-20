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

    iterator func_00164150();

    char allocator;
    Node *head;
    unsigned int size;
};

// The list's begin: the first node after the head node, or none without a head node (an out-of-line copy of the
// inline member; 0x1641E0, 0x164350 and 0x174760 call it).
Object_00174220::iterator Object_00174220::func_00164150()
{
    return iterator(head == 0 ? 0 : head->next);
}
