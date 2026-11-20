struct Game {
    char unknown_0000[0x98];
    void *objects[0x1df4];

    void func_00012870(int id, void *object);
};

// Registers an object under an id.
void Game::func_00012870(int id, void *object)
{
    if (id >= 0 && id < 0x1df4) {
        objects[id] = object;
    }
}
