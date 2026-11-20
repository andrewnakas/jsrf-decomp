struct Node {
    virtual ~Node();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

};

struct Game {
    void func_00012840(Node *node);
};

// Takes a node out of the draw list.
void Game::func_00012840(Node *node)
{
    if (node->drawTail) {
        *node->drawLink = node->drawNext;
        if (node->drawNext) {
            node->drawNext->drawLink = node->drawLink;
        } else {
            *node->drawTail = node->drawLink;
        }
    }
}
