/* sym: ??0Game@@QAE@HH@Z = 0x00012210 */
// The game (0x8840 bytes, table 0x1C4458, destructor 0x12390).
struct Game {
    Game(int first, int second);
    virtual ~Game();

    void func_00012C10();
    int func_00013F80();

    char unknown_0004[0x883c];
};

extern Game *data_0022FCE0;

// The game's entry point, called from 0x147FB4 with three zero arguments (0x148005-0x14800B, a main's argc, argv
// and envp, unused): makes the game object (0x22FCE0), runs func_00012C10 and the main loop func_00013F80, deletes
// it and returns 0.
int func_0006F9E0(int argc, char **argv, char **envp)
{
    data_0022FCE0 = new Game(0, 0);
    data_0022FCE0->func_00012C10();
    data_0022FCE0->func_00013F80();
    delete data_0022FCE0;
    return 0;
}
