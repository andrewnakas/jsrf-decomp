struct Node {
    virtual ~Node();

    unsigned int flags;
    char unknown_08[0x2c];
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct NodeList {
    Node *head;
    Node **tail;
};

struct Game {
    char unknown_0000[0x7f9c];
    NodeList lists[2];

    void func_000127F0(Node *node);
};

// Appends a node to one of the two lists chosen by flag 1, unless flag 0x40000000 keeps it out of both.
void Game::func_000127F0(Node *node)
{
    if (node->flags & 0x40000000) {
        node->drawNext = 0;
        node->drawLink = 0;
        node->drawTail = 0;
        return;
    }
    Node ***tail;
    if (node->flags & 1) {
        tail = &lists[0].tail;
    } else {
        tail = &lists[1].tail;
    }
    node->drawLink = *tail;
    **tail = node;
    *tail = &node->drawNext;
    node->drawNext = 0;
    node->drawTail = tail;
}
