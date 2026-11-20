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
        bool operator!=(const iterator &other) const
        {
            return node != other.node;
        }
    };

    // Unlinks and frees the node at `where` (never the head node) and returns the iterator after it.
    iterator erase(iterator where)
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
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// Erases the nodes from `first` up to `last` and returns `last`. The lists with 0x10-byte nodes (head node 0x16E310)
// and 0x20-byte nodes (0x175AD0) use this same function.
Object_00174220::iterator Object_00174220::func_0016E2C0(iterator first, iterator last) throw()
{
    while (first != last)
        erase(first++);
    return first;
}
