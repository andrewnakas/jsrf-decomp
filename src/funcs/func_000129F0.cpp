struct Node;

struct Game {
    char unknown_0000[0x7fac];
    Node *drawHead;
    Node **drawTail;

    Node *func_000129F0();
};

Node *Game::func_000129F0()
{
    return drawHead;
}
