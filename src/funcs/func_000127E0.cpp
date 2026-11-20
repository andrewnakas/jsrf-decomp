struct Game {
    char unknown_0000[0x7868];
    int values[1];

    int func_000127E0(int index);
};

int Game::func_000127E0(int index)
{
    return values[index];
}
