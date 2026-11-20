struct Game {
    char unknown_0000[0x58];
    int unknown_0058;
    int unknown_005c;

    void func_000126F0(int which);
};

void Game::func_000126F0(int which)
{
    if (which) {
        unknown_0058 = 1;
    } else {
        unknown_005c = 1;
    }
}
