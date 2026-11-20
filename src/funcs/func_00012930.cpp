struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
};

struct Game {
    char unknown_0000[0x98];
    Node *objects[0x1df4];

    void func_00012930(int first, int second);
};

// Swaps the objects registered under two ids.
void Game::func_00012930(int first, int second)
{
    Node *object = objects[first];
    objects[first] = objects[second];
    objects[second] = object;
    if (objects[first]) {
        objects[first]->id = first;
    }
    if (objects[second]) {
        objects[second]->id = second;
    }
}
