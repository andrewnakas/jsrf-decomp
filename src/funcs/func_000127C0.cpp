struct Game {
    char unknown_0000[0x7868];
    int values[1];

    void func_000127C0(int index, int value);
};

void Game::func_000127C0(int index, int value)
{
    values[index] = value;
}
