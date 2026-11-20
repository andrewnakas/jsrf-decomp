struct Node {
    virtual ~Node();

    char unknown_04[0x3c];
    Node *sortedNext;
};

struct Game {
    char unknown_0000[0x7fac];
    Node *sortedHead;
    Node **sortedTail;

    void func_00012A00(Node *node);
};

// Appends a node to the list at +0x7fac (linked through the nodes' +0x40).
void Game::func_00012A00(Node *node)
{
    node->sortedNext = 0;
    *sortedTail = node;
    sortedTail = &node->sortedNext;
}
