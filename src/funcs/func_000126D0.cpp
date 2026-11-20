struct Game {
    char unknown_0000[0x50];
    int unknown_0050;
    int unknown_0054;

    void func_000126D0(int which);
};

void Game::func_000126D0(int which)
{
    if (which) {
        unknown_0050 = 1;
    } else {
        unknown_0054 = 1;
    }
}
