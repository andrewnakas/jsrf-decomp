struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;

    void func_00011B60(Node *first, Node *newParent);
    void func_00012020(Node *newParent);
};

struct Game {
    char unknown_0000[0x87dc];
    Node *root;

    void func_000127F0(Node *node);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Links the node in as the last child of a parent (or of object 0, or as the game's root) and puts it in a draw list.
void Node::func_00012020(Node *newParent)
{
    if (newParent) {
        if (newParent->flags & 0x40000001) {
            flags |= 0x40000000;
        }
        Node *last = newParent->child;
        if (last) {
            while (last->next) {
                last = last->next;
            }
            last->next = this;
            previous = last;
            parent = newParent;
        } else {
            newParent->child = this;
            parent = newParent;
        }
    } else if (data_0022FCE0->root) {
        Node *root = (Node *)data_0022FCE0->func_000128C0(0);
        if (root->child) {
            func_00011B60(root->child, root);
        } else {
            root->child = this;
            parent = root;
        }
    } else {
        data_0022FCE0->root = this;
        parent = 0;
    }
    data_0022FCE0->func_000127F0(this);
}
