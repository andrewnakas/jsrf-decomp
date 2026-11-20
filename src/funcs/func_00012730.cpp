struct Game {
    char unknown_0000[0x68];
    int unknown_0068;
    int unknown_006c;

    void func_00012730(int which);
};

void Game::func_00012730(int which)
{
    if (which) {
        unknown_0068 = 1;
    } else {
        unknown_006c = 1;
    }
}
