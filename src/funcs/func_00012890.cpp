struct Game {
    char unknown_0000[0x98];
    void *objects[0x1df4];

    void func_00012890(int id);
};

// Removes the object registered under an id.
void Game::func_00012890(int id)
{
    if (id >= 0 && objects[id]) {
        objects[id] = 0;
    }
}
