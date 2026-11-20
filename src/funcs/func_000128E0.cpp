struct Game {
    char unknown_0000[0x98];
    void *objects[0x1df4];

    int func_000128E0(int first, int last);
};

// Returns the first id in [first, last] with no object registered, or -1.
int Game::func_000128E0(int first, int last)
{
    for (int id = first; id <= last; id++) {
        if (!objects[id]) {
            return id;
        }
    }
    return -1;
}
