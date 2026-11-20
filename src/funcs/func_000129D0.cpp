struct Node;

struct Game {
    char unknown_0000[0x7fac];
    Node *drawHead;
    Node **drawTail;

    void func_000129D0();
};

extern Game *data_0022FCE0;

// Empties the draw list.
void Game::func_000129D0()
{
    drawHead = 0;
    drawTail = &data_0022FCE0->drawHead;
}
