struct Game {
    char unknown_0000[0x60];
    int unknown_0060;
    int unknown_0064;

    void func_00012710(int which);
};

void Game::func_00012710(int which)
{
    if (which) {
        unknown_0060 = 1;
    } else {
        unknown_0064 = 1;
    }
}
