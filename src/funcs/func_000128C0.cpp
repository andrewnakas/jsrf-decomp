struct Game {
    char unknown_0000[0x98];
    void *objects[0x1df4];

    void *func_000128C0(int id);
};

// Returns the object registered under an id.
void *Game::func_000128C0(int id)
{
    if (id >= 0) {
        return objects[id];
    }
    return 0;
}
