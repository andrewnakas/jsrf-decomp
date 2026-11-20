struct Game {
    char unknown_00[0x38];
    int unknown_0038;
    int unknown_003c;

    void func_00012AC0(int first, int second);
};

void Game::func_00012AC0(int first, int second)
{
    unknown_003c = second;
    unknown_0038 = first;
}
