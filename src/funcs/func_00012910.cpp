struct Game {
    char unknown_0000[0x98];
    void *objects[0x1df4];

    int func_00012910(int id);
};

// Says whether an id has no object registered. Retail reads the entry into a register of its own (0x12915)
// and tests it there (0x1291e), so the entry is a named local.
int Game::func_00012910(int id)
{
    void *object = objects[id];
    return object == 0;
}
