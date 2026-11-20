void __cdecl operator delete(void *memory) throw();

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
        iterator operator++(int)
        {
            iterator before = *this;
            node = node->next;
            return before;
        }
    };

    iterator func_001741E0(iterator where);

    char allocator;
    Node *head;
    unsigned int size;
};

// Unlinks and frees the node at `where` (never the head node) and returns the iterator after it: the list's erase,
// which slot 11 of the class whose table is at 0x1E3DE4 (0x174760) calls.
Object_00174220::iterator Object_00174220::func_001741E0(iterator where)
{
    Node *node = (where++).node;
    if (node != head) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        operator delete(node);
        --size;
    }
    return where;
}
