struct Node {
    void func_00011220();
    void func_00011450();
    void func_00011680();
    void func_000118B0();
    void func_00011AE0();
};

struct Game {
    char unknown_0000[0x40];
    int unknown_0040;
    int unknown_0044;
    int unknown_0048;
    int unknown_004c;

    void func_00012680(Node *node);
};

// Walks a tree with the walker the game's mode fields select.
void Game::func_00012680(Node *node)
{
    if (node) {
        if (unknown_0040) {
            node->func_00011680();
            return;
        }
        if (unknown_0044) {
            node->func_00011450();
            return;
        }
        if (unknown_0048) {
            node->func_000118B0();
            return;
        }
        if (unknown_004c) {
            node->func_00011AE0();
            return;
        }
        node->func_00011220();
    }
}
