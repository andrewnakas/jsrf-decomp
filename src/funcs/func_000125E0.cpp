/* const: 0x200000 */
/* const: 0x80000 */
struct Node {
    void func_000110A0(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
    void func_000112D0(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
    void func_00011500(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
    void func_00011730(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
    void func_00011960(unsigned int include, int argument, int sortedArgument, unsigned int required, unsigned int maskBits,
                       unsigned int exclude, unsigned int twice);
};

// The game (constructor 0x12210).
struct Game {
    virtual ~Game();

    char unknown_0004[0x3c];
    int unknown_0040;
    int unknown_0044;
    int unknown_0048;
    int unknown_004c;
    char unknown_0050[0x7f54];
    Node *scene;

    void func_000125E0(unsigned int include, int argument, int sortedArgument, unsigned int required,
                       unsigned int maskBits, int masked, int both);
};

// Called by func_00012C80 and func_000131F0: draws the node tree at +0x7fa4 with the first of func_00011500,
// func_000112D0, func_00011730 and func_00011960 whose switch (+0x40, +0x44, +0x48, +0x4c) is set, else
// func_000110A0. Without `masked` nodes get flag 0x80000 as `twice`; with it and `both`, 0x200000 is excluded.
void Game::func_000125E0(unsigned int include, int argument, int sortedArgument, unsigned int required,
                         unsigned int maskBits, int masked, int both)
{
    unsigned int exclude;
    unsigned int twice;
    if (masked) {
        if (both) {
            exclude = 0x200000;
            twice = 0;
        } else {
            exclude = 0;
            twice = 0;
        }
    } else {
        exclude = 0;
        twice = 0x80000;
    }
    if (scene) {
        if (unknown_0040)
            scene->func_00011500(include, argument, sortedArgument, required, maskBits, exclude, twice);
        else if (unknown_0044)
            scene->func_000112D0(include, argument, sortedArgument, required, maskBits, exclude, twice);
        else if (unknown_0048)
            scene->func_00011730(include, argument, sortedArgument, required, maskBits, exclude, twice);
        else if (unknown_004c)
            scene->func_00011960(include, argument, sortedArgument, required, maskBits, exclude, twice);
        else
            scene->func_000110A0(include, argument, sortedArgument, required, maskBits, exclude, twice);
    }
}
